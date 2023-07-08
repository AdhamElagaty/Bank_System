#include <iostream>
#include <iomanip>
#include "ScreenTheme.h"
#include "Screens.h"
#include "Client.h"
#include "Validation.h"
using namespace std;

Client::Client(){
    balance = 0.0;
}

Client::Client(string first_name, string second_name, string password, double balance) :
        Person(first_name,second_name,password){
    this->set_balance(balance);
}

Client::Client(string id, string first_name, string second_name, string password, double balance) :
Person(id,first_name,second_name,password){
    this->set_balance(balance);
}

bool Client::set_balance(double balance) {
    while (!Validation::isValidBalance(balance)){
        string bal;
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Edite Invalid Balance";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        ScreenTheme::color_style(12);
        cout << "\t\t\t\t\t\t\t\t\t  Error! Invalid Balance :( " << endl;
        cout << "\t\t\t\t\t\t\t\t\t  to Open Account do you need deposit more than 1500." << endl;
        ScreenTheme::color_style(7);
        cout << "\t\t\t\t\t\t\t\t\t  Please Enter Balance Again : ";
        bal = ScreenTheme::take_num_input();
        if (bal == "!x!"){
            return false;
        }
        balance = stod(bal);
    }
    this->balance = balance;
    return true;
}

double Client::get_balance() {
    return this->balance;
}

void Client::deposit(double amount) {
    if (amount > 0) {
        this->balance += amount;
        edit_client_balance();
    }
}

bool Client::withdraw(double amount) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
        edit_client_balance();
        return true;
    }else
    {
        return false;
    }
}

bool Client::transferTo(double amount, Client &recipient) {
    if (amount > 0 && amount <= (this->balance-1500.0)) {
        this->balance -= amount;
        edit_client_balance();
        recipient.deposit(amount);
        return true;
    }else{
        return false;
    }
}

void Client::checkBalance(){
    cout << "\t\t\t\t\t\t\t\t\t   *************************************" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   *              *                    *" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   * Your Balance *    " << left << setw(15) << this->balance << " *" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   *              *                    *" << endl;
    cout << "\t\t\t\t\t\t\t\t\t   *************************************" << endl;
}

void Client::edit_client_password() {
    vector<Client> c = f.get_all_clients();
    f.remove_all_clients();
    for(Client &C : c){
        if (C.get_id() == this->id){
            C.set_password(this->password);
        }
        f.add_client(C);
    }
}

void Client::edit_client_balance() {
    vector<Client> c = f.get_all_clients();
    f.remove_all_clients();
    for(Client &C : c){
        if (C.get_id() == this->id){
            C.set_balance(this->balance);
        }
        f.add_client(C);
    }
}

void Client::display(){
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t*";
    cout << "      ID                  Name                      Balance       ";
    cout << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
    cout << "\t\t\t\t\t\t\t\t*     " << left << setw(18) << this->get_id() << left << setw(29) << this->get_name() << left << setw(14) << this->get_balance() << "*" << endl;
    cout << "\t\t\t\t\t\t\t\t********************************************************************" <<endl;
}
