#ifndef ADMIN_DATASOURCEINTERFACE_H
#define ADMIN_DATASOURCEINTERFACE_H
#include <vector>
using namespace std;

class Admin;

class Admin_DataSourceInterface {
public:
    virtual void add_admin(Admin &a, bool generateID = true) = 0;
    virtual vector<Admin> get_all_admins() = 0;
    virtual void remove_all_admins() = 0;
    virtual Employee* search_employee(int id) = 0;
};
#endif
