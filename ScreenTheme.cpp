#include <windows.h>
#include <conio.h>
#include "ScreenTheme.h"
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void ScreenTheme::color_style(WORD color) {
    SetConsoleTextAttribute(h,color);
}

void ScreenTheme::go_to_xy(short x, short y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}

int ScreenTheme::choose_them(string menu, int num_ch, short X, short Y){
    int* Set = new int[num_ch], counter = 1;
    char key;
    for (int i = 0; i < num_ch; ++i) {
        Set[i] = 7;
    }
    while (true)
    {
        short x = X, y = Y;
        int nc = 0;
        for (int j = 0; j < num_ch; ++j) {
            if (counter == j+1){
                Set[j] = 12;
            }
        }
        for (int i = 0; i < menu.length(); ++i) {
            if (menu[i] == '\n'){
                go_to_xy(x,y);
                y++;
                continue;
            }
            if (menu[i] == '#' && Set[nc] != 7){
                color_style(7);
            }
            cout << menu[i];
            if(menu[i] == '.'){
                nc = int(menu[i-1]-'0')-1;
                color_style(Set[nc]);
            }
        }
        key = _getch();
        Set[counter-1] = 7;
        if(key == 72 && (counter >=1 && counter <= num_ch))
        {
            if(counter == 1){
                counter = num_ch;
            }else{
                counter--;
            }
        }
        if(key == 80 && (counter >=1 && counter <= num_ch))
        {
            if(counter == num_ch){
                counter = 1;
            } else{
                counter++;
            }
        }
        if(key == '\r')
        {
            for (int i = 0; i < num_ch; ++i) {
                if (counter == i+1){
                    delete[] Set;
                    return counter;
                }
            }
        }
    }
}

string ScreenTheme::take_num_input(int size) {
    string num = "";
    char ch_ipt;
    while (true) {
        ch_ipt = getch();
        if(isdigit(ch_ipt) && num.length() <= (size-1)){
            num.push_back(ch_ipt);
            cout << ch_ipt;
        }else{
            if (ch_ipt == 13) {
                cout << endl;
                return num;
            }else if(ch_ipt == 27){
                num = "!x!";
                cout << endl;
                return num;
            }
            else if (ch_ipt == 8 && num.length() != 0) {
                num.pop_back();
                cout << "\b \b";
                continue;
            }
            else if (ch_ipt == 8 && num.length() == 0) {
                continue;
            }
        }
    }
}

string ScreenTheme::take_alphabet_input(int size) {
    string alphabet = "";
    char ch_ipt;
    while (true) {
        ch_ipt = getch();
        if(isalpha(ch_ipt) && !isspace(ch_ipt) && alphabet.length() <= (size-1)){
            alphabet.push_back(ch_ipt);
            cout << ch_ipt;
        }else{
            if (ch_ipt == 13) {
                cout << endl;
                return alphabet;
            }else if(ch_ipt == 27){
                alphabet = "!x!";
                cout << endl;
                return alphabet;
            }
            else if (ch_ipt == 8 && alphabet.length() != 0) {
                alphabet.pop_back();
                cout << "\b \b";
                continue;
            }
            else if (ch_ipt == 8 && alphabet.length() == 0) {
                continue;
            }
        }
    }
}
