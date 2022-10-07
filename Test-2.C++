#include <stdio.h>
#include <iostream>

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

    cout << "Input location of repo in local file system:" << endl;
    cin >> Repo_loc;

    cout << "Input location of picture in local file system:" << endl;
    cin >> Pic_loc;

    Last_BSlash = Pic_loc.find_last_of(BSlash);

    Pic_loc_temp = Pic_loc;
    Pic_name = Pic_loc.erase(0, Last_BSlash);
    Pic_loc = Pic_loc_temp;

    New_Pic_loc = Repo_loc + "\\" + Pic_name;

    if (rename(Pic_loc.c_str(),New_Pic_loc.c_str()))
    perror( NULL );

    return 0;
}

// Debugging block: 
    // cout << Repo_loc << endl; // Repository location
    // cout << Pic_loc << endl; // Picture location
    // cout << Pic_loc_temp << endl; // Picture location
    // cout << New_Pic_loc << endl; // Picture location
    // cout << Pic_name << endl; // Picture file name
    // cout << BSlash << endl; // String "\\"
    // cout << Last_BSlash << endl; // Location of last "\\" in String Pic_loc