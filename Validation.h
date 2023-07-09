#include <iostream>
using namespace std;

class Validation {
public:
    static bool isValidName(string name);
    static bool isValidPassword(string password);
    static bool isValidBalance(double balance);
    static bool isValidSalary(double salary);
    static bool isValidPhone(string phone_number);
    static bool isValidNationalId(string national_id);
};

