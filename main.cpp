#include <iostream>
#include "Screens.h"
#include "ClientManger.h"
#include "FilesHelper.h"
#include "Password.h"
#include "ScreenTheme.h"
#include "Employee.h"
using namespace std;

int main() {
    system("cls");
    Screens::loading_screen();
    Screens::welcome();
    Screens::login_options();
    return 0;
}
