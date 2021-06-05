#include <iostream>
#include <unistd.h>

using namespace std;

int aleator(int a)
{
    srand(time(0));
    return rand() % 10;
}

int main()
{
    int c = 0, s, p = -1;
    long long g = 0;
    do
    {
        p++;
        system("clear");
        c = aleator(10);
        g = g * 10 + c;
        cout << g << endl;
        sleep(2);
        system("clear");
        cout << "Ce numar a fost afisat?";
        cin >> s;
    } while (s == g);
    cout << "Ai obtinut " << p << " punte!"
         << "\n"
         << "Ultimul numar afisat a fost " << g << "\n";
    return 0;
}
