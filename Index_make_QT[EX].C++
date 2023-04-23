#include "mainwindow.h"

#include <QApplication>

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdint>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();



    string Repo_loc; // Repository location
    string Pic_loc; // Picture location
    string Pic_loc_temp; // Picture location
    string New_Pic_loc; // Picture location
    string Pic_name; // Picture file name
    string BSlash = "\\"; // String "\\"
    size_t Last_BSlash; // Location of last "\\" in String Pic_loc
    string Index_loc;
    string Pic_tags;
    string Pic_type;
    string Pic_Ctime;


    QLineEdit::imageLocationLineEdit = Repo_loc;

    cout << "Input location of picture in local file system:" << endl;
    cin >> Pic_loc;

    cout << "Input Image type [Comic, Landscape, Photogrammetry, Etc]:" << endl;
    cin >> Pic_type;

    cout << "Input desired tags separated by commas:" << endl;
    cin.ignore();
    getline(cin, Pic_tags);

    cout << "Input date of creation [Type ~ in front if estimated Type N/A if unknown]:" << endl;
    cin >> Pic_Ctime;


    Last_BSlash = Pic_loc.find_last_of(BSlash);

    Pic_loc_temp = Pic_loc;
    Pic_name = Pic_loc.erase(0, Last_BSlash);
    Pic_loc = Pic_loc_temp;

    New_Pic_loc = Repo_loc + "//" + Pic_name;

    if (rename(Pic_loc.c_str(),New_Pic_loc.c_str()))
    perror( NULL );


    Index_loc = Repo_loc + "\\Index.txt";

    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);

    ofstream foutput;
    ifstream finput;

    finput.open (Index_loc);
    foutput.open (Index_loc,ios::app);

    if(finput.is_open())
        foutput << "Link: https://raw.githubusercontent.com/UCDrones-research/Drone-image-database/main/Repo" << Pic_name << "   Image Type: " << Pic_type << "   Tags: " << Pic_tags << "   Date added: " <<t.tm_mon+1<<"/"<<t.tm_mday<<"/"<<t.tm_year+1900 << "   Date created: " << Pic_Ctime << endl;

    finput.close();
    foutput.close();

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