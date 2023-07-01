#include <iostream>
#include <string>
#include <conio.h>
#include "Password.h"
using namespace std;

string Password::takePasswdFromUser(){
    char sp = '*';
    string passwd = "";
    char ch_ipt;
    while (true) {
        ch_ipt = getch();
        if (ch_ipt == 13) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == 8 && passwd.length() != 0) {
            passwd.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (ch_ipt == 8 && passwd.length() == 0) {
            continue;
        }
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

string Password::encrypt_password(string password, string id) {
    int key = stoi(id)%1000;
    string pass = password;
    for (int i = 0; i < password.length(); ++i) {
        pass[i] = pass[i] + (key+i);
    }
    return pass;
}
