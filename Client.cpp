#include <iostream>
#include "Client.h"
#include "Validation.h"
using namespace std;

Client::Client(){
    balance = 0.0;
}

Client::Client(string id, string first_name, string second_name, string password, double balance) :
Person(id,first_name,second_name,password){
    if (Validation::isValidBalance(balance)){
        this->balance = balance;
    }else{
        throw invalid_argument("Invalid Balance");
    }
}

void Client::set_balance(double balance) {
    if (Validation::isValidBalance(balance)){
        this->balance = balance;
    }else{
        throw invalid_argument("Invalid Balance");
    }
}

double Client::get_balance() {
    return this->balance;
}

void Client::deposit(double amount) {
    if (amount > 0) {
        this->balance += amount;
    }else
    {
        throw invalid_argument("Invalid Amount");
    }
}

void Client::withdraw(double amount) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
    }else
    {
        throw invalid_argument("Invalid Amount to Withdraw");
    }
}

void Client::transferTo(double amount, Client &recipient) {
    if (amount > 0 && amount <= this->balance) {
        this->balance -= amount;
        recipient.deposit(amount);
    }else{
        throw invalid_argument("Invalid Amount to Transfer");
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
