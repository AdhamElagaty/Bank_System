#ifndef ADMIN_DATASOURCEINTERFACE_H
#define ADMIN_DATASOURCEINTERFACE_H
#include <vector>
using namespace std;

class Admin;

class Admin_DataSourceInterface {
public:
    virtual void add_admin() = 0;
    virtual vector<Admin> get_all_admin() = 0;
    virtual void remove_all_admin() = 0;
};
#endif
