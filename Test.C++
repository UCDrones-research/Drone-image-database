#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

    string Repo_loc; // Repository location
    string Pic_loc; // Picture location
    string BSlash; // String "\\"
    size_t Last_BSlash; // Location of last "\\" in String Pic_loc

    cout << "Input location of repo in local file system:" << endl;
    cin >> Repo_loc;

    cout << "Input location of picture in local file system:" << endl;
    cin >> Pic_loc;

    Last_BSlash = Pic_loc.find_last_of(BSlash);
    std::string BSlash = Pic_loc.substr(0, Pic_loc.find("%"));
    
    cout << Pic_loc << endl;
    

    if ( rename("C:\\Users\\Zero\\Desktop\\New Text Document.txt", "C:\\Users\\Zero\\Desktop\\Test\\New Text Document.txt") )
        perror( NULL );
    return 0;
}
