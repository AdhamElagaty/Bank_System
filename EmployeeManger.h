#include "ClientManger.h"
#include "Employee.h"
#ifndef EMPLOYEEMANGER_H
#define EMPLOYEEMANGER_H

class EmployeeManger : public ClientManger{
protected:
    static int print_employee_menu();
    static void update_password(Employee* employee);
public:
};
#endif
