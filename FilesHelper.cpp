#include <ctime>
#include "FilesHelper.h"
#include "Parser.h"
using namespace std;

void FilesHelper::saveLast(string last_id_file, int id) {
    ofstream LId_out;
    LId_out.open(last_id_file);
    LId_out << id << endl;
    LId_out.close();
}

int FilesHelper::getLast(string last_id_file) {
    ifstream Lid_in;
    int x = 0;
    Lid_in.open(last_id_file);
    Lid_in >> x;
    Lid_in.close();
    return x;
}

int FilesHelper::generate_id(std::string last_id_file) {
    time_t now = time(nullptr);
    tm * t = localtime(&now);
    int y =  (((t ->tm_year)+1900)%100)*1000, id;
    if (getLast(last_id_file) == 0 || (getLast(last_id_file)/1000) != (y/1000)){
        id = ++y;
    } else{
        id = getLast(last_id_file) + 1;
    }
    saveLast(last_id_file,id);
    return id;
}

void FilesHelper::saveClient(Client c) {
    ofstream client_out;
    client_out.open("Clients.txt", ios::app);
    int id = generate_id("Last_id_Clients.txt");
    c.set_id(to_string(id));
    client_out << c.get_id() << "," << c.get_name() << "," << c.get_password() << "," << c.get_balance() << endl;
    client_out.close();
}

void FilesHelper::saveEmployee(string file_name, string last_id_file, Employee e) {
    ofstream employee_out;
    employee_out.open(file_name);
    int id = generate_id(last_id_file);
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
    ifstream file("Admins.txt");
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

Client* FilesHelper::SearchClient(int id) {
    ifstream file("Clients.txt");
    string line;
    while (getline(file, line)) {
        Client* c = new Client(Parser::parse_to_client(line));
        if(c->get_id() == to_string(id))
        {
            file.close();
            return c;
        }
    }
    file.close();
    return nullptr;
}

Employee* FilesHelper::SearchEmployee(int id) {
    ifstream file("Employees.txt");
    string line;
    while (getline(file, line)) {
        Employee* e = new Employee(Parser::parse_to_employee(line));
        if(e->get_id() == to_string(id))
        {
            file.close();
            return e;
        }
    }
    file.close();
    return nullptr;
}