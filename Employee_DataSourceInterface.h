#ifndef EMPLOYEE_DATASOURCEINTERFACE_H
#define EMPLOYEE_DATASOURCEINTERFACE_H
#include <vector>
using namespace std;

class Employee;

class Employee_DataSourceInterface {
public:
    virtual void add_employee(Employee e) = 0;
    virtual vector<Employee> get_all_employees() = 0;
    virtual void remove_all_employees() = 0;
};
#endif
