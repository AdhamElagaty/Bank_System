#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "FileManager.h"
using namespace std;

class Employee : public Person{
protected:
    double salary;
    FileManager f;
public:
    Employee();
    Employee(string id, string first_name, string second_name, string password,string phone_number, string national_id, double salary);
    bool set_salary(double salary);
    double get_salary();
    void display();
    void add_client(Client& client);
    Client* search_client(int id);
    void list_client();
    void edit_client(int id, string first_name, string second_name, string password, string phone_number);
    void display_with_national_id();
    void edit_password_in_file();
};
#endif