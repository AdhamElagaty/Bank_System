#include <iostream>
#include "Person.h"
#include "Validation.h"
#include "Password.h"
using namespace std;

Person::Person() {}

Person::Person(string first_name, string second_name, string password) {
    this->set_name(first_name,second_name);
    this->set_password(password);
}

Person::Person(string id, string first_name, string second_name, string password) {
    this->id = id;
    this->set_name(first_name,second_name);
    this->set_password(password);
}

void Person::set_name(string first_name, string second_name) {
    while (!Validation::isValidName(first_name+second_name)){
        cout << "Error! Invalid Name :( " << endl;
        cout << "Please Enter First Name Again : ";
        cin >> first_name;
        cout << "Please Enter Second Name Again : ";
        cin >> second_name;
    }
    this->first_name = first_name;
    this->second_name = second_name;
}

void Person::set_password(string password) {
    while (!Validation::isValidPassword(password)){
        cout << "Error! Invalid Password :( " << endl;
        cout << "Please Enter Password Again : ";
        password = Password::takePasswdFromUser();
    }
    this->password = password;
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
