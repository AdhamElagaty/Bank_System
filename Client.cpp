#include <iostream>
#include <iomanip>
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

void Client::set_balance(double balance) {
    while (!Validation::isValidBalance(balance)){
        cout << "Error! Invalid Balance :( " << endl;
        cout << "Please Enter Balance Again : ";
        cin >> balance;
    }
    this->balance = balance;
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

void Client::withdraw(double amount) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
    }else
    {
        cout << "Error! Invalid Amount to Withdraw :(" << endl;
    }
}

void Client::transferTo(double amount, Client &recipient) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
        recipient.deposit(amount);
    }else{
        cout << "Error! Invalid Amount to Transfer :(" << endl;
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
