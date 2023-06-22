#include <iostream>
#include "Employee.h"
#include "Validation.h"
using namespace std;

Employee::Employee() {
    this->salary = 0.0;
}

Employee::Employee(string id, string first_name, string second_name, string password,double salary) :
Person(id,first_name,second_name,password)
{
    this->set_salary(salary);
}

void Employee::set_salary(double salary) {
    while (!Validation::isValidSalary(salary)){
        cout << "Error! Invalid Salary :( " << endl;
        cout << "Please Enter Salary Again : ";
        cin >> salary;
    }
    this->salary = salary;
}

double Employee::get_salary() {
    return this->salary;
}

void Employee::display() {
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->get_name() << endl;
    cout << "Salary: " << this->salary << endl;
}