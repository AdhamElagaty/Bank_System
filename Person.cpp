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