#include "FileManager.h"

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
}

void FileManager::add_client(Client c) {
    FilesHelper::saveClient(c);
}

void FileManager::add_employee(Employee e) {
    FilesHelper::saveEmployee(employee_file,employee_file_last_id,e);
}

void FileManager::add_admin(Admin a) {
    FilesHelper::saveEmployee(admin_file,admin_file_last_id,a);
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


