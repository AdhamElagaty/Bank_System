#include "ScreenTheme.h"
#include "FilesHelper.h"
#include "Validation.h"
#include "Password.h"
#include "Screens.h"
#include "Person.h"
using namespace std;

Person::Person() {
}

Person::Person(string first_name, string second_name, string password, string phone_number, string national_id) {
    this->set_name(first_name+" "+second_name);
    this->set_password(password);
    this->set_phone_number(phone_number);
    this->set_national_id(national_id);
}

Person::Person(string id, string first_name, string second_name, string password, string phone_number, string national_id) {
    this->id = id;
    this->set_name(first_name+" "+second_name);
    this->set_password(password);
    this->set_phone_number(phone_number);
    this->set_national_id(national_id);
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
        f_name = ScreenTheme::take_alphabet_input(12);
        if (f_name == "!x!"){
            return false;
        }
        cout << "\t\t\t\t\t\t\t\t\t  Please Enter Second Name Again : ";
        s_name = ScreenTheme::take_alphabet_input(12);
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

bool Person::set_phone_number(string phone_number) {
    while (!Validation::isValidPhone(phone_number)){
        string NPhone;
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Edite Invalid Phone Number";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        ScreenTheme::color_style(12);
        cout << "\t\t\t\t\t\t\t\t\t  Error! Invalid Phone Number :( " << endl;
        ScreenTheme::color_style(7);
        cout << "\t\t\t\t\t\t\t\t\t  Please Enter Phone Number Again : ";
        NPhone = ScreenTheme::take_num_input(11);
        if (NPhone == "!x!"){
            return false;
        }
        phone_number = NPhone;
    }
    if (phone_number == ""){
        this->phone_number = "xxxxxxxxxxx";
    }else{
        this->phone_number = phone_number;
    }
    return true;
}

bool Person::set_national_id(string national_id) {
    int size = national_id.length();
    if (national_id[size-1] == 'x'){
        national_id.erase(size-1,1);
        while (!Validation::isValidNationalId(national_id)){
            string NID;
            system("cls");
            Screens::header_screen();
            ScreenTheme::color_style(11);
            cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
            ScreenTheme::color_style(7);
            cout << "Edite Invalid National ID";
            ScreenTheme::color_style(11);
            cout << " #$#$#$" << endl;
            ScreenTheme::color_style(7);
            cout << "\n\n";
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t\t  Error! Invalid National ID :( " << endl;
            ScreenTheme::color_style(7);
            cout << "\t\t\t\t\t\t\t\t\t  Please Enter National ID Again : ";
            NID = ScreenTheme::take_num_input(14);
            if (NID == "!x!"){
                return false;
            }
            national_id = NID;
        }
    }
    this->national_id = national_id;
    return true;
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

string Person::get_phone_number() {
    return this->phone_number;
}

string Person::get_national_id() {
    return this->national_id;
}
