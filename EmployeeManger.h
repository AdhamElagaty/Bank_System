#ifndef EMPLOYEEMANGER_H
#define EMPLOYEEMANGER_H
#include "ClientManger.h"
#include "Employee.h"

class EmployeeManger : public ClientManger{
protected:
    static int print_employee_menu();
    static void display_employee_info(Employee employee);
    static void add_new_client(Employee* employee);
    static void list_all_client(Employee* employee);
    static void search_for_client(Employee* employee);
    static int check_national_id(Person *person);
    static void edit_client_info(Employee* employee, Client* client);
    static void edit_name_of_client(Employee* employee, Client* client);
    static void edit_phone_number_of_client(Employee* employee, Client* client);
    static void reset_password_of_client(Employee* employee, Client* client);
public:
    static Employee* login(string id, string password);
    static void employee_options(Employee* employee);
};
#endif
