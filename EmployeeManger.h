#ifndef EMPLOYEEMANGER_H
#define EMPLOYEEMANGER_H
#include "ClientManger.h"
#include "Employee.h"

class EmployeeManger : public ClientManger{
protected:
    static int print_employee_menu();
    static void update_password(Employee* employee);
    static void display_employee_info(Employee employee);
    static void add_new_client(Employee* employee);
    static void list_all_client(Employee* employee);
public:
    static Employee* login(string id, string password);
    static void employee_options(Employee* employee);
};
#endif
