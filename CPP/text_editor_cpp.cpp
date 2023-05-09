#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen()
{
    system("cls");
}

int main()
{
    string fileName;
    ofstream file;
    ifstream readFile;
    string line;
    int x = 0, y = 0;
    char ch;

    while (true) {
        clearScreen();
        cout << "Enter file name: ";
        cin >> fileName;

        file.open(fileName.c_str());

        if (file.is_open()) {
            gotoxy(0, 0);
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
        else {
            file.clear();
            file.open(fileName.c_str(), ios::out);
            file.close();
        }

        x = y = 0;
        gotoxy(x, y);

        while (true) {
            ch = _getch();
            if (ch == 13) { // Enter key
                x = 0;
                y++;
                gotoxy(x, y);
            }
            else if (ch == 27) { // ESC key
                break;
            }
            else if (ch == 8) { // Backspace key
                if (x > 0) {
                    x--;
                    gotoxy(x, y);
                    cout << " ";
                    gotoxy(x, y);
                }
            }
            else {
                cout << ch;
                x++;
                gotoxy(x, y);
                file.open(fileName.c_str(), ios::app);
                file << ch;
                file.close();
            }
        }
    }

    return 0;
}

/**
 * @brief basic text editor on which you can build up better version.
 * 
 */