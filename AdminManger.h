#ifndef ADMINMANGER_H
#define ADMINMANGER_H
#include "EmployeeManger.h"


class AdminManger : public  EmployeeManger{
private:
    static int print_admin_menu();
};
#endif
