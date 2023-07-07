#include <iostream>
#include <string>
#include <conio.h>
#include "ScreenTheme.h"
#include "Screens.h"
#include "Password.h"
using namespace std;

string Password::takePasswdFromUser(){
    char sp = '*';
    string passwd = "";
    char ch_ipt;
    while (true) {
        ch_ipt = _getch();
        if (ch_ipt == 13) {
            cout << endl;
            return passwd;
        }else if(ch_ipt == 27){
            cout << endl;
            passwd = "!x!";
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

string Password::decrypt_password(string password, string id) {
    int key = stoi(id)%1000;
    string pass = password;
    for (int i = 0; i < password.length(); ++i) {
        pass[i] = pass[i] - (key+i);
    }
    return pass;
}

string Password::Enter_new_password() {
    string newPass, confirmPass;
    int attempt = 3;
    do{
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Create Password*";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        if (attempt < 3){
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t\t\t   Passwords do not match :(" << endl;
            ScreenTheme::color_style(7);
            cout << "\t\t\t\t\t\t\t\t\t\t   You has ";
            ScreenTheme::color_style(12);
            cout << attempt;
            ScreenTheme::color_style(7);
            cout << " Attempt" << endl;
        }
        cout << "\t\t\t\t\t\t\t\t\t\t   Enter new password: ";
        newPass = Password::takePasswdFromUser();
        if(newPass == "!x!"){
            continue;
        }
        cout << "\t\t\t\t\t\t\t\t\t\t   Confirm new password: ";
        confirmPass = Password::takePasswdFromUser();
        if(confirmPass == "!x!"){
            continue;
        }
        if (newPass == confirmPass) {
            break;
        }
        attempt--;
    }while(attempt != 0);
    if (attempt == 0){
        return "";
    }
    return newPass;
}
