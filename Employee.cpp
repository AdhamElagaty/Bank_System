#include <iostream>
#include "Employee.h"
#include "Validation.h"
using namespace std;

Employee::Employee() {
    this->salary = 0.0;
}

Employee::Employee(std::string id, std::string first_name, std::string second_name, std::string password,double salary):
Person(id,first_name,second_name,password)
{
    if (Validation::isValidSalary(salary)){
        this->salary = salary;
    }
    else{
        throw invalid_argument("Invalid Salary");
    }
}

void Employee::set_salary(double salary) {
    if (Validation::isValidSalary(salary)){
        this->salary = salary;
    }
    else{
        throw invalid_argument("Invalid Salary");
    }
}

double Employee::get_salary() {
    return this->salary;
}

void Employee::display() {
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->get_name() << endl;
    cout << "Salary: " << this->salary << endl;
}