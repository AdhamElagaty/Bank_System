#include <windows.h>
#include <conio.h>
#ifndef SCREENS_H
#define SCREENS_H
using namespace std;


class Screens {
public:
    static void view_date_and_time();
    static void loading_screen();
    static void bank_name();
    static void welcome();
    static void header_screen();
    static int login_as_menu();
    static void login_screen(int num);
    static void login_options();
};
#endif
