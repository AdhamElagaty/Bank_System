#ifndef ADMINMANGER_H
#define ADMINMANGER_H
#include "Admin.h"
#include "EmployeeManger.h"


class AdminManger : public  EmployeeManger{
private:
    static int print_admin_menu();
public:
    static Admin* login(string id, string password);
};
#endif
