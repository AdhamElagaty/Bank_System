#include "ScreenTheme.h"
#include "Validation.h"
#include "Password.h"
#include "Screens.h"
#include "Person.h"
using namespace std;

Person::Person() {}

Person::Person(string first_name, string second_name, string password) {
    this->set_name(first_name+" "+second_name);
    this->set_password(password);
}

Person::Person(string id, string first_name, string second_name, string password) {
    this->id = id;
    this->set_name(first_name+" "+second_name);
    this->set_password(password);
}

bool Person::set_name(string name) {
    while (!Validation::isValidName(name)){
        string f_name, s_name;
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Edite Invalid Name";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        ScreenTheme::color_style(12);
        cout << "\t\t\t\t\t\t\t\t\t  Error! Invalid Name :( " << endl;
        ScreenTheme::color_style(7);
        cout << "\t\t\t\t\t\t\t\t\t  Please Enter First Name Again : ";
        f_name = ScreenTheme::take_alphabet_input();
        if (f_name == "!x!"){
            return false;
        }
        cout << "\t\t\t\t\t\t\t\t\t  Please Enter Second Name Again : ";
        s_name = ScreenTheme::take_alphabet_input();
        if (s_name == "!x!"){
            return false;
        }
        name = f_name + " " + s_name;
    }
    string result[2];
    string item;
    stringstream Name(name);
    int i = 0;
    while (getline(Name, item, ' ')) {
        result[i] = item;
        i++;
    }
    this->first_name = result[0];
    this->second_name = result[1];
    return true;
}

void Person::set_password(string password) {
    string *PCH = new string(password);
    while (!Validation::isValidPassword(*PCH)){

        *PCH = Password::Enter_new_password();
    }
    this->password = *PCH;
    delete PCH;
}

void Person::set_id(string id) {
    this->id = id;
}

string Person::get_first_name() {
    return this->first_name;
}

string Person::get_second_name() {
    return this->second_name;
}

string Person::get_name() {
    return (this->first_name + " " + this->second_name);
}

string Person::get_password() {
    return this->password;
}

string Person::get_id() {
    return this->id;
}
