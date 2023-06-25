#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "Person.h"
using namespace std;

class Client : public Person{
private:
    double balance;
public:
    Client();
    Client(string first_name, string second_name, string password, double balance);
    Client(string id, string first_name, string second_name, string password, double balance);
    void set_balance(double balance);
    double get_balance();
    void deposit(double amount);
    void withdraw(double amount);
    void transferTo(double amount, Client& recipient);
    void checkBalance();
    void display();
};
#endif