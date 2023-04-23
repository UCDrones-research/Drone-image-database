// Initial draft of Qt c++ integration

#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdint>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string Repo_loc; // Repository location
    std::string Pic_loc; // Picture location
    std::string Pic_loc_temp; // Picture location
    std::string New_Pic_loc; // Picture location
    std::string Pic_name; // Picture file name
    std::string BSlash = "\\"; // String "\\"
    size_t Last_BSlash; // Location of last "\\" in String Pic_loc
    std::string Index_loc;
    std::string Pic_tags;
    std::string Pic_type;
    std::string Pic_Ctime;

    std::cout << "Input location of repo in local file system:" << std::endl;
    std::cin >> Repo_loc;

    std::cout << "Input location of picture in local file system:" << std::endl;
    std::cin >> Pic_loc;

    std::cout << "Input Image type [Comic, Landscape, Photogrammetry, Etc]:" << std::endl;
    std::cin >> Pic_type;

    std::cout << "Input desired tags separated by commas:" << std::endl;
    std::cin.ignore();
    getline(std::cin, Pic_tags);

    std::cout << "Input date of creation [Type ~ in front if estimated Type N/A if unknown]:" << std::endl;
    std::cin >> Pic_Ctime;

    Last_BSlash = Pic_loc.find_last_of(BSlash);

    Pic_loc_temp = Pic_loc;
    Pic_name = Pic_loc.erase(0, Last_BSlash);
    Pic_loc = Pic_loc_temp;

    New_Pic_loc = Repo_loc + "//" + Pic_name;

    if (QFile::rename(QString::fromStdString(Pic_loc), QString::fromStdString(New_Pic_loc)))
        perror(NULL);

    Index_loc = Repo_loc + "\\Index.txt";

    time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);

    std::ofstream foutput;
    std::ifstream finput;

    finput.open(Index_loc);
    foutput.open(Index_loc, std::ios::app);

    if (finput.is_open())
        foutput << "Link: https://raw.githubusercontent.com/UCDrones-research/Drone-image-database/main/Repo" << Pic_name << "   Image Type: " << Pic_type << "   Tags: " << Pic_tags << "   Date added: " << t.tm_mon + 1 << "/" << t.tm_mday << "/" << t.tm_year + 1900 << "   Date created: " << Pic_Ctime << std::endl;

    finput.close();
    foutput.close();

    return a.exec();
}
