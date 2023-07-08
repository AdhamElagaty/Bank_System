#include <iostream>
#include "Employee.h"
#include "Validation.h"
#include <iomanip>
using namespace std;

Employee::Employee() {
    this->salary = 0.0;
}

Employee::Employee(string id, string first_name, string second_name, string password,double salary) :
Person(id,first_name,second_name,password)
{
    this->set_salary(salary);
}

void Employee::set_salary(double salary) {
    while (!Validation::isValidSalary(salary)){
        cout << "Error! Invalid Salary :( " << endl;
        cout << "Please Enter Salary Again : ";
        cin >> salary;
    }
    this->salary = salary;
}

double Employee::get_salary() {
    return this->salary;
}

void Employee::display() {
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t*";
    cout << "      ID                  Name                      Salary        ";
    cout << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t*     " << left << setw(18) << this->get_id() << left << setw(29) << this->get_name() << left << setw(14) << this->get_salary() << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
}

void Employee::add_client(Client &client) {
    f.add_client(client);
}

Client *Employee::search_client(int id) {
    return f.search_client(id);
}

void Employee::list_client() {
    vector<Client> c = f.get_all_clients();
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t*";
    cout << "      ID                  Name                      Balance       ";
    cout << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
    for(Client &C : c){
        cout << "\t\t\t\t\t\t\t\t*     " << left << setw(18) << C.get_id() << left << setw(29) << C.get_name() << left << setw(14) << C.get_balance() << "*" << endl;
    }
    cout << "\t\t\t******************************************************" <<endl;
}

void Employee::edit_employee_password() {
    vector<Employee> e = f.get_all_employees();
    f.remove_all_employees();
    for(Employee &E : e){
        if (E.get_id() == this->id){
            E.set_password(this->password);
        }
        f.add_employee(E);
    }
}

void Employee::edit_client(int id, string first_name, string second_name, string password, double balance) {
    vector<Client> c = f.get_all_clients();
    f.remove_all_clients();
    for(Client &C : c){
        if (C.get_id() == to_string(id)){
            C.set_name(first_name + " " + second_name);
            C.set_password(password);
            C.set_balance(balance);
        }
        f.add_client(C);
    }
}
