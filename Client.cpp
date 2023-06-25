#include <iostream>
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
    cout << "Balance: " << this->balance << endl;
}

void Client::display(){
    cout << "ID: " << this->id << endl;
    cout << "Name: " << this->get_name() << endl;
    cout << "Balance: " << this->balance << endl;
}
