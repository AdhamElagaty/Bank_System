#include <iostream>
#include <iomanip>
#include "Admin.h"
using namespace std;

Admin::Admin() {}

Admin::Admin(string id, string first_name, string second_name, string password,string phone_number, string national_id, double salary) :
Employee(id,first_name,second_name,password,phone_number,national_id,salary){}

void Admin::add_employee(Employee &employee) {
    f.add_employee(employee);
}

Employee* Admin::search_employee(int id) {
    return f.search_employee(id);
}

void Admin::list_employee() {
    vector<Employee> e = f.get_all_employees();
    cout << "\t\t\t\t\t\t\t\t\t*******************************************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t\t*";
    cout << "      ID                  Name                Phone Number                  Salary       ";
    cout << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t\t*******************************************************************************************" <<endl;
    for(Employee &E : e){
        cout << "\t\t\t\t\t\t\t\t\t*     " << left << setw(16) << E.get_id() << left << setw(25) << E.get_name() << left << setw(28) << E.get_phone_number() << left << setw(15) << E.get_salary() << "*" << endl;
    }
    cout << "\t\t\t\t\t\t\t\t\t*******************************************************************************************" <<endl;
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

void Admin::edit_password_in_file() {
    vector<Admin> a = f.get_all_admins();
    f.remove_all_admins();
    for(Admin &A : a){
        if (A.get_id() == this->id){
            A.set_password(this->password);
        }
        f.add_admin(A);
    }
}
