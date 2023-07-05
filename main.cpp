#include <iostream>
#include "Screens.h"
#include "Employee.h"
using namespace std;

int main() {
    Screens::loading_screen();
    Screens::welcome();
    Screens::header_screen();
    system("pause");
    return 0;
}
