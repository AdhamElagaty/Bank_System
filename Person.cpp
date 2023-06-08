#include "Person.h"
#include "Validation.h"

Person::Person() {}

Person::Person(string first_name, string second_name, string password) {
    if (Validation::isValidName(first_name+second_name)) {
        this->first_name = first_name;
        this->second_name = second_name;
    } else {
        throw invalid_argument("Invalid Name");
    }
    if (Validation::isValidPassword(password)) {
        this->password = password;
    } else {
        throw invalid_argument("Invalid Password");
    }
}

Person::Person(string id, string first_name, string second_name, string password) {
    this->id = id;
    if (Validation::isValidName(first_name+second_name)) {
        this->first_name = first_name;
        this->second_name = second_name;
    } else {
        throw invalid_argument("Invalid Name");
    }
    if (Validation::isValidPassword(password)) {
        this->password = password;
    } else {
        throw invalid_argument("Invalid Password");
    }
}

void Person::set_name(string first_name, string second_name) {
    if(Validation::isValidName(first_name+second_name)){
        this->first_name = first_name;
        this->second_name = second_name;
    }else{
        throw invalid_argument("Invalid Name");
    }
}

void Person::set_password(string password) {
    if (Validation::isValidPassword(password)){
        this->password = password;
    }else{
        throw invalid_argument("Invalid Password");
    }
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
