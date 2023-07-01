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
    Employee(string id, string first_name, string second_name, string password, double salary);
    void set_salary(double salary);
    double get_salary();
    void display();
    void add_client(Client& client);
    Client* search_client(int id);
    void list_client();
    void edit_client(int id, string first_name, string second_name, string password, double balance);
};
#endif