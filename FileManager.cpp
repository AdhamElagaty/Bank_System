#include "FileManager.h"
#include "FilesHelper.h"

FileManager::FileManager() {
    client_file = "Clients.txt";
    employee_file = "Employees.txt";
    admin_file = "Admins.txt";
    client_file_last_id = "Last_id_Clients.txt";
    employee_file_last_id = "Last_id_Employees.txt";
    admin_file_last_id = "Last_id_Admins.txt";
    ofstream client_out(client_file, ios::app);
    client_out.close();
    ofstream employee_out(employee_file, ios::app);
    employee_out.close();
    ofstream admin_out(admin_file, ios::app);
    admin_out.close();
//    ofstream client_out_lastID(client_file_last_id, ios::app);
//    client_out_lastID.close();
//    ofstream employee_out_lastID(employee_file_last_id, ios::app);
//    employee_out_lastID.close();
//    ofstream admin_out_lastID(admin_file_last_id, ios::app);
//    admin_out_lastID.close();
}

void FileManager::add_client(Client &c, bool generateID) {
    FilesHelper::saveClient(c, generateID);
}

void FileManager::add_employee(Employee &e, bool generateID) {
    FilesHelper::saveEmployee(employee_file,employee_file_last_id,e, generateID);
}

void FileManager::add_admin(Admin &a, bool generateID) {
    FilesHelper::saveEmployee(admin_file,admin_file_last_id,a, generateID);
}

vector<Client> FileManager::get_all_clients() {
    return FilesHelper::getClients();
}

vector<Employee> FileManager::get_all_employees() {
    return FilesHelper::getEmployees();
}

vector<Admin> FileManager::get_all_admins() {
    return FilesHelper::getAdmins();
}

void FileManager::remove_all_clients() {
    FilesHelper::clearFile(client_file,client_file_last_id);
}

void FileManager::remove_all_employees() {
    FilesHelper::clearFile(employee_file,employee_file_last_id);
}

void FileManager::remove_all_admins() {
    FilesHelper::clearFile(admin_file,admin_file_last_id);
}

Client *FileManager::search_client(int id) {
    return FilesHelper::SearchClient(id);
}

Employee *FileManager::search_employee(int id) {
    return FilesHelper::SearchEmployee(id);
}


