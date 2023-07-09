#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include "Employee.h"
using namespace std;

class Admin : public Employee{
public:
    Admin();
    Admin(string id, string first_name, string second_name, string password,string phone_number, string national_id, double salary);
    void add_employee(Employee& employee);
    Employee* search_employee(int id);
    void list_employee();
    void edit_employee(int id, string first_name, string second_name, string password, double Salary);
};
#endif
