#ifndef EMPLOYEE_DATASOURCEINTERFACE_H
#define EMPLOYEE_DATASOURCEINTERFACE_H
#include <vector>
using namespace std;

class Employee;

class Employee_DataSourceInterface {
public:
    virtual void add_employee() = 0;
    virtual vector<Employee> get_all_clients() = 0;
    virtual void remove_all_employee() = 0;
};
#endif
