#include <iostream>
#include "Validation.h"
using namespace std;

bool Validation::isValidName(string name) {
    if (name.length() < 8 || name.length() > 20) {
        return false;
    }
    for (int i = 0; i < name.length(); ++i) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool Validation::isValidPassword(string password) {
    if (password.length() < 8 || password.length() > 20) {
        return false;
    }
    return true;
}

bool Validation::isValidBalance(double balance) {
    return balance >= 1500;
}

bool Validation::isValidSalary(double salary) {
    return salary >= 5000;
}
