#include <iostream>
#include <iomanip>
#include "Admin.h"
using namespace std;

Admin::Admin() {}

Admin::Admin(string id, string first_name, string second_name, string password, double salary) :
Employee(id,first_name,second_name,password,salary){}

void Admin::add_employee(Employee &employee) {
    f.add_employee(employee);
}

Employee* Admin::search_employee(int id) {
    return f.search_employee(id);
}

void Admin::list_employee() {
    vector<Employee> e = f.get_all_employees();
    cout << "\t\t\t******************************************************" <<endl;
    cout << "\t\t\t*";
    cout << "      ID               Name             Salary     ";
    cout << "*" << endl;
    cout << "\t\t\t******************************************************" <<endl;
    for(Employee &E : e){
        cout << "\t\t\t*     " << left << setw(15) << E.get_id()    << left << setw(22) << E.get_name() << left << setw(10) << E.get_salary() << setw(6) << "*" << endl;
    }
    cout << "\t\t\t******************************************************" <<endl;
}

void Admin::edit_employee(int id, string first_name, string second_name, string password, double Salary) {
    vector<Employee> e = f.get_all_employees();
    f.remove_all_employees();
    for(Employee &E : e){
        if (E.get_id() == to_string(id)){
            E.set_name(first_name + " " + second_name);
            E.set_password(password);
            E.set_salary(salary);
        }
        f.add_employee(E);
    }
}
