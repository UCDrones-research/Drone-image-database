#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>     
#include <string> 
#include <cstdint>

using namespace std;

int main()
{

    string Repo_loc; // Repository location
    string Pic_loc; // Picture location
    string Pic_loc_temp; // Picture location
    string New_Pic_loc; // Picture location
    string Pic_name; // Picture file name
    string BSlash = "\\"; // String "\\"
    size_t Last_BSlash; // Location of last "\\" in String Pic_loc
    string Index_loc; // Location of index
    string Pic_tags;  // Picture tags
    string Pic_type; // Picture type 
    string Pic_Ctime; // Time of picture upload

    cout << "Input location of repo in local file system:" << endl;
    cin >> Repo_loc; // Ask for and receive location of repo

    cout << "Input location of picture in local file system:" << endl;
    cin >> Pic_loc; // Ask for and receive location of picture

    cout << "Input Image type [Comic, Landscape, Photogrammetry, Etc]:" << endl;
    cin >> Pic_type; // Ask for and receive picture type

    cout << "Input desired tags separated by commas:" << endl;
    cin.ignore(); 
    getline(cin, Pic_tags); // Ask for receive and organize picture tags

    cout << "Input date of creation [Type ~ in front if estimated Type N/A if unknown]:" << endl;
    cin >> Pic_Ctime; // Ask for and receive date of creation


    Last_BSlash = Pic_loc.find_last_of(BSlash); // Find The last instance of "\" in The picture location

    Pic_loc_temp = Pic_loc; // Makes a temporary copy of the picture location
    Pic_name = Pic_loc.erase(0, Last_BSlash); // Isolates the file name of the picture by Erasingall of the contents of the string before the last set of backslashes.
    Pic_loc = Pic_loc_temp; // Overrides the Picture location with the contents of temporary version.

    New_Pic_loc = Repo_loc + "//" + Pic_name; //Creates the new picture location by Appending the picture file name to the path of the repository.

    if (rename(Pic_loc.c_str(),New_Pic_loc.c_str()))
    perror( NULL ); // Moves the image into the repository

     
    Index_loc = Repo_loc + "\\Index.txt"; //Generates the allocation of the index file by appending index dot TXT to the repo location/

    time_t tmNow; 
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow); // Get current time

    ofstream foutput;  
    ifstream finput; 

    finput.open (Index_loc); // Opens the index dot TXT file
    foutput.open (Index_loc,ios::app); 
 
    if(finput.is_open())
        foutput << "Link: https://raw.githubusercontent.com/UCDrones-research/Drone-image-database/main/Repo" << Pic_name << "   Image Type: " << Pic_type << "   Tags: " << Pic_tags << "   Date added: " <<t.tm_mon+1<<"/"<<t.tm_mday<<"/"<<t.tm_year+1900 << "   Date created: " << Pic_Ctime << endl; 
        // Outputs a line to the index dot TXT file with all of the prior inputted data and a link to the final image uploaded to GitHub.
    finput.close();
    foutput.close(); // Closes the index dot TXT file

    return 0; // end
}

// Debugging block: 
    // cout << Repo_loc << endl; // Repository location
    // cout << Pic_loc << endl; // Picture location
    // cout << Pic_loc_temp << endl; // Picture location
    // cout << New_Pic_loc << endl; // Picture location
    // cout << Pic_name << endl; // Picture file name
    // cout << BSlash << endl; // String "\\"
    // cout << Last_BSlash << endl; // Location of last "\\" in String Pic_loc