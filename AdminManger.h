#ifndef ADMINMANGER_H
#define ADMINMANGER_H
#include "Admin.h"
#include "EmployeeManger.h"


class AdminManger : public  EmployeeManger{
private:
    static int print_admin_menu();
    static void display_admin_info(Admin admin);
    static void add_new_employee(Admin* admin);
    static void list_all_employee(Admin *admin);
    static void search_for_employee(Admin *admin);
    static void edit_salary(Admin *admin, Employee *employee);
    static void edit_employee_info(Admin *admin, Employee *employee);
    static void edit_name_of_employee(Admin* admin, Employee* employee);
    static void edit_phone_number_of_employee(Admin* admin, Employee* employee);
    static void reset_password_of_employee(Admin* admin, Employee* employee);
public:
    static Admin* login(string id, string password);
    static void admin_options(Admin* admin);
};
#endif
