#include <iostream>
#include <cstring>

using namespace std;

char s[250];

int main()
{
    // cin >> s;
    char s[] = "DAN MARIS; DANILA PREPELEAC; DAN POPA; EDANA DAN; ";

    char sep[] = ";";
    char *p = strtok(s, sep);
    while (p != NULL)
    {
        
        cout << p << endl;
        p = strtok(NULL, sep);
    }

    // cout << strtok(s, ".");
    // cout << endl;
    // cout << strtok(NULL, ".");

    // cout << s;
    // cout << endl;
    // cout << strlen(strtok(s, "."));
    // strcpy(s, s + strlen(strtok(s, ".")));
    // cout << endl
    //      << s;
    // cout << strtok(s, ".");
    // cout << strtok(s, ".");

    // cout << strtok(s, ";");
    // while(strtok(s, ";") != NULL){
    //     cout << strtok(s, ";");
    // }

    return 0;
}