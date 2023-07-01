#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <fstream>
#include "Client_DataSourceInterface.h"
#include "Employee_DataSourceInterface.h"
#include "Admin_DataSourceInterface.h"
using namespace std;


class FileManager : public Client_DataSourceInterface, public Employee_DataSourceInterface, public Admin_DataSourceInterface{
private:
    string client_file, employee_file, admin_file, client_file_last_id, employee_file_last_id, admin_file_last_id;
public:
    FileManager();
    void add_client(Client c);
    void add_employee(Employee e);
    void add_admin(Admin a);
    vector<Client> get_all_clients();
    vector<Employee> get_all_employees();
    vector<Admin> get_all_admins();
    void remove_all_clients();
    void remove_all_employees();
    void remove_all_admins();
    Client* search_client(int id);
    Employee* search_employee(int id);
};
#endif
