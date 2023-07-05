#include <iostream>
#include "Screens.h"
#include "ClientManger.h"
#include "FilesHelper.h"
using namespace std;

int main() {
    system("cls");
    Screens::loading_screen();
    Screens::welcome();
    ClientManger::client_options(FilesHelper::SearchClient(42110049));
    system("pause");
    return 0;
}
