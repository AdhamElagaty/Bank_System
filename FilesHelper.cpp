#include "FilesHelper.h"

void FilesHelper::saveLast(string last_id_file, int id) {
    ofstream LId_out;
    LId_out.open(last_id_file);
    LId_out << id << endl;
    LId_out.close();
}

int FilesHelper::getLast(string last_id_file) {
    ifstream Lid_in;
    int x;
    Lid_in.open(last_id_file);
    Lid_in >> x;
    Lid_in.close();
    return x;
}

void FilesHelper::saveClient(Client c) {
    ofstream client_out;
    client_out.open("Clients.txt", ios::app);
    int id = getLast("Last_id_Clients.txt") + 1;
    saveLast("Last_id_Clients.txt",id);
    c.set_id(to_string(id));
    client_out << c.get_id() << "," << c.get_name() << "," << c.get_password() << "," << c.get_balance() << endl;
    client_out.close();
}

void FilesHelper::saveEmployee(string file_name, string last_id_file, Employee e) {
    ofstream employee_out;
    employee_out.open(file_name);
    int id = getLast(last_id_file) + 1;
    saveLast(last_id_file,id);
    e.set_id(to_string(id));
    employee_out << e.get_id() << "," << e.get_name() << "," << e.get_password() << "," << e.get_salary() << endl;
    employee_out.close();
}

vector<Client> FilesHelper::getClients() {
    vector<Client> C;
    ifstream file("Clients.txt");
    string line;
    while (getline(file, line)) {
        Client c = Parser::parse_to_client(line);
        C.push_back(c);
    }
    file.close();
    return C;
}

vector<Employee> FilesHelper::getEmployees() {
    vector<Employee> E;
    ifstream file("Employees.txt");
    string line;
    while (getline(file, line)) {
        Employee e = Parser::parse_to_employee(line);
        E.push_back(e);
    }
    file.close();
    return E;
}

vector<Admin> FilesHelper::getAdmins() {
    vector<Admin> A;
    ifstream file("Clients.txt");
    string line;
    while (getline(file, line)) {
        Admin a = Parser::parse_to_admin(line);
        A.push_back(a);
    }
    file.close();
    return A;
}

void FilesHelper::clearFile(string file_name, string last_id_file) {
    ofstream file;
    file.open(file_name, ios::trunc);
    file.close();
    file.open(last_id_file, ios::trunc);
    file.close();
}