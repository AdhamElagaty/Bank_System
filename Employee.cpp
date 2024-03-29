#include <iostream>
#include "ScreenTheme.h"
#include "Screens.h"
#include "Employee.h"
#include "Validation.h"
#include <iomanip>
using namespace std;

Employee::Employee() {
    this->salary = 0.0;
}

Employee::Employee(string id, string first_name, string second_name, string password, string phone_number, string national_id, double salary) :
Person(id,first_name,second_name,password,phone_number,national_id)
{
    this->set_salary(salary);
}

bool Employee::set_salary(double salary) {
    while (!Validation::isValidSalary(salary)){
        string sal;
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Edite Invalid Salary";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
        ScreenTheme::color_style(12);
        cout << "ESC";
        ScreenTheme::color_style(7);
        cout << "'" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        ScreenTheme::color_style(12);
        cout << "\t\t\t\t\t\t\t\t\t  Error! Invalid Salary :( " << endl;
        cout << "\t\t\t\t\t\t\t\t\t  Do you need to set Salary more than 5000." << endl;
        ScreenTheme::color_style(7);
        cout << "\t\t\t\t\t\t\t\t\t  Please Enter Salary Again : ";
        sal = ScreenTheme::take_num_input(7);
        if (sal == "!x!"){
            return false;
        }
        salary = stod(sal);
    }
    this->salary = salary;
    return true;
}

double Employee::get_salary() {
    return this->salary;
}

void Employee::display() {
    cout << "\t\t\t\t\t\t*******************************************************************************************" <<endl;
    cout << "\t\t\t\t\t\t*";
    ScreenTheme::color_style(90);
    cout << "      ID                  Name                Phone Number               Salary          ";
    ScreenTheme::color_style(7);
    cout << "*" << endl;
    cout << "\t\t\t\t\t\t*******************************************************************************************" <<endl;
    cout << "\t\t\t\t\t\t*     " << left << setw(16) << this->get_id() << left << setw(25) << this->get_name() << left << setw(28) << this->get_phone_number() << left << setw(15) << this->get_salary() << "*" << endl;
    cout << "\t\t\t\t\t\t*******************************************************************************************" <<endl;
}

void Employee::add_client(Client &client) {
    f.add_client(client);
}

Client *Employee::search_client(int id) {
    return f.search_client(id);
}

void Employee::list_client() {
    vector<Client> c = f.get_all_clients();
    cout << "\t\t\t\t\t\t\t\t\t*******************************************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t\t*";
    ScreenTheme::color_style(90);
    cout << "      ID                  Name                Phone Number                  Balance      ";
    ScreenTheme::color_style(7);
    cout << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t\t*******************************************************************************************" <<endl;
    for(Client &C : c){
        cout << "\t\t\t\t\t\t\t\t\t*     " << left << setw(16) << C.get_id() << left << setw(25) << C.get_name() << left << setw(28) << C.get_phone_number() << left << setw(15) << C.get_balance() << "*" << endl;
    }
    cout << "\t\t\t\t\t\t\t\t\t*******************************************************************************************" <<endl;
}


void Employee::edit_client(int id, string first_name, string second_name, string password,string phone_number) {
    vector<Client> c = f.get_all_clients();
    f.remove_all_clients();
    for(Client &C : c){
        if (C.get_id() == to_string(id)){
            C.set_name(first_name + " " + second_name);
            C.set_password(password);
            C.set_phone_number(phone_number);
        }
        f.add_client(C, false);
    }
}

void Employee::display_with_national_id() {
    cout << "\t\t\t\t\t     ***********************************************************************************************************" <<endl;
    cout << "\t\t\t\t\t     *";
    ScreenTheme::color_style(90);
    cout << "      ID                  Name                Phone Number          National ID           Salary         ";
    ScreenTheme::color_style(7);
    cout << "*" << endl;
    cout << "\t\t\t\t\t     ***********************************************************************************************************" <<endl;
    cout << "\t\t\t\t\t     *     " << left << setw(16) << this->get_id() << left << setw(25) << this->get_name() << left << setw(21) << this->get_phone_number() << left << setw(24) << this->get_national_id() << left << setw(14) << this->get_salary() << "*" << endl;
    cout << "\t\t\t\t\t     ***********************************************************************************************************" <<endl;
}

void Employee::edit_password_in_file() {
    vector<Employee> e = f.get_all_employees();
    f.remove_all_employees();
    for(Employee &E : e){
        if (E.get_id() == this->id){
            E.set_password(this->password);
        }
        f.add_employee(E, false);
    }
}
