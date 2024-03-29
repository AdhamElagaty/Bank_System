#ifndef FILESHELPER_H
#define FILESHELPER_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class FilesHelper {
private:
    static void saveLast(string last_id_file, int id);
    static int getLast(string last_id_file);
    static int generate_id(string last_id_file);
    static void save_national_id(string national_id);
public:
    static void saveClient(Client &c, bool generateID = true);
    static void saveEmployee(string file_name, string last_id_file, Employee &e, bool generateID = true);
    static vector<Client> getClients();
    static vector<Employee> getEmployees();
    static vector<Admin> getAdmins();
    static void clearFile(string file_name, string last_id_file);
    static Client* SearchClient(int id);
    static Employee* SearchEmployee(int id);
    static Admin* search_admin(int id);
    static bool IsFound_national_id(string national_id);
};
#endif
