#include "Person.h"
#include "Validation.h"

Person::Person() {}

Person::Person(string first_name, string second_name, string password) {
    if (Validation::isValidName(first_name+second_name)) {
        this->first_name = first_name;
        this->second_name = second_name;
    } else {
        throw invalid_argument("Invalid name");
    }
    if (Validation::isValidPassword(password)) {
        this->password = password;
    } else {
        throw invalid_argument("Invalid password");
    }
}

Person::Person(string id, string first_name, string second_name, string password) {
    this->id = id;
    if (Validation::isValidName(first_name+second_name)) {
        this->first_name = first_name;
        this->second_name = second_name;
    } else {
        throw invalid_argument("Invalid name");
    }
    if (Validation::isValidPassword(password)) {
        this->password = password;
    } else {
        throw invalid_argument("Invalid password");
    }
}

void Person::set_first_name(string first_name) {
    this->first_name = first_name;
}

void Person::set_second_name(string second_name) {
    this->second_name = second_name;
}

void Person::set_name(string first_name, string second_name) {
    this->first_name = first_name;
    this->second_name = second_name;
}

void Person::set_password(std::string password) {
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
