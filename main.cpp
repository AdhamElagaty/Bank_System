#include <iostream>
#include "Password.h"
using namespace std;

int main() {
    string x, z;
    cin >> x;
    z = Password::encrypt_password(x,"23006");
    cout << z << endl;
    cout << Password::decrypt_password(z,"23006") << endl;
    system("pause");
    return 0;
}
