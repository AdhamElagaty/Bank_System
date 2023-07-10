#ifndef ADMINMANGER_H
#define ADMINMANGER_H
#include "Admin.h"
#include "EmployeeManger.h"


class AdminManger : public  EmployeeManger{
private:
    static int print_admin_menu();
    static void display_admin_info(Admin admin);
    static void add_new_employee(Admin* admin);
public:
    static Admin* login(string id, string password);
    static void admin_options(Admin* admin);
};
#endif
