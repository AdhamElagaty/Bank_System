#ifndef SCREENTHEME_H
#define SCREENTHEME_H
#include <iostream>
#include <windows.h>
using namespace std;

class ScreenTheme {
public:
    static void color_style(WORD color);
    static void go_to_xy(short x, short y);
    static int choose_them(string menu, int num_ch, short X, short Y);
    static string take_num_input(int size);
    static string take_alphabet_input(int size);
};
#endif
