#include <iostream>
#include <ctime>
#include "Password.h"
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
    return id;
}

void FilesHelper::save_national_id(string national_id){
    ofstream LNationalID_out;
    LNationalID_out.open("Nationals_ID.txt", ios::app);
    LNationalID_out << national_id << endl;
    LNationalID_out.close();
}

void FilesHelper::saveClient(Client &c, bool generateID) {
    ofstream client_out;
    client_out.open("Clients.txt", ios::app);
    if(generateID){
        int id = generate_id("Last_id_Clients.txt");
        c.set_id(to_string(id));
        save_national_id(c.get_national_id());
    }
    if(c.get_password() == ""){
        c.set_password(c.get_id()+"00000000");
    }
    string password = Password::encrypt_password(c.get_password(),c.get_id());
    client_out << c.get_id() << "," << c.get_name() << "," << password << "," << c.get_phone_number() << "," << c.get_national_id() << "," << c.get_balance() << endl;
    saveLast("Last_id_Clients.txt", stoi(c.get_id()));
    client_out.close();
}

void FilesHelper::saveEmployee(string file_name, string last_id_file, Employee &e, bool generateID) {
    ofstream employee_out;
    employee_out.open(file_name, ios::app);
    if(generateID) {
        int id = generate_id(last_id_file);
        e.set_id(to_string(id));
        save_national_id(e.get_national_id());
    }
    if(e.get_password() == ""){
        e.set_password(e.get_id()+"00000000");
    }
    save_national_id(e.get_national_id());
    string password = Password::encrypt_password(e.get_password(),e.get_id());
    employee_out << e.get_id() << "," << e.get_name() << "," << password << "," << e.get_phone_number() << "," << e.get_national_id() << "," << e.get_salary() << endl;
    saveLast(last_id_file, stoi(e.get_id()));
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
        Client* c = new Client();
        *c = Parser::parse_to_client(line);
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

Admin* FilesHelper::search_admin(int id){
    ifstream file("Admins.txt");
    string line;
    while (getline(file, line)) {
        Admin* a = new Admin(Parser::parse_to_admin(line));
        if(a->get_id() == to_string(id))
        {
            file.close();
            return a;
        }
    }
    file.close();
    return nullptr;
}

bool FilesHelper::IsFound_national_id(string national_id) {
    ifstream file("Nationals_ID.txt");
    string line;
    while (getline(file,line)){
        if (national_id == line){
            return true;
        }
    }
    return false;
}
