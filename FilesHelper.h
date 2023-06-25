#include <iostream>
#include <vector>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;

class FilesHelper {
private:
    static void saveLast(string last_id_file, int id);
    static int getLast(string last_id_file);
public:
    static void saveClient(Client c);
    static void saveEmployee(string file_name, string last_id_file, Employee e);
    static vector<Client> getClients();
    static vector<Employee> getEmployees();
    static vector<Admin> getAdmins();
    static void clearFile(string file_name, string last_id_file);
};
