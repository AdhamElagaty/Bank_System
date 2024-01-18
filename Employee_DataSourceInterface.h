#ifndef EMPLOYEE_DATASOURCEINTERFACE_H
#define EMPLOYEE_DATASOURCEINTERFACE_H
#include <vector>
using namespace std;

class Employee;

class Employee_DataSourceInterface {
public:
    virtual void add_employee(Employee &e, bool generateID = true) = 0;
    virtual vector<Employee> get_all_employees() = 0;
    virtual void remove_all_employees() = 0;
    virtual Client* search_client(int id) = 0;
};
#endif
