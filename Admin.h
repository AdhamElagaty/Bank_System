#include <iostream>
#include "Employee.h"
using namespace std;

class Admin : public Employee{
public:
    Admin();
    Admin(string id, string first_name, string second_name, string password,double salary);
};

