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
    int* Set = new int[num_ch], counter = 2;
    char key;
    for (int i = 0; i < num_ch; ++i) {
        Set[i] = 7;
    }
    while (true)
    {
        short x = X, y = Y;
        int nc = 0;
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
        for (int j = 0; j < num_ch; ++j) {
            if (counter == j+1){
                Set[j] = 12;
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