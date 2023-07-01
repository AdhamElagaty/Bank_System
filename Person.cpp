#include "Person.h"
#include "Validation.h"
#include "Password.h"

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

void Person::set_name(string name) {
    while (!Validation::isValidName(name)){
        string f_name, s_name;
        cout << "Error! Invalid Name :( " << endl;
        cout << "Please Enter First Name Again : ";
        cin >> f_name;
        cout << "Please Enter Second Name Again : ";
        cin >> s_name;
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
}

void Person::set_password(string password) {
    static string PCH = password;
    while (!Validation::isValidPassword(PCH)){
        cout << "Error! Invalid Password :( " << endl;
        cout << "Please Enter Password Again : ";
        PCH = Password::takePasswdFromUser();
    }
    this->password = password;
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
