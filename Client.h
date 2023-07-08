#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include "Person.h"
#include "FileManager.h"
using namespace std;

class Client : public Person{
private:
    double balance;
    FileManager f;
public:
    Client();
    Client(string first_name, string second_name, string password, double balance);
    Client(string id, string first_name, string second_name, string password, double balance);
    bool set_balance(double balance);
    double get_balance();
    void deposit(double amount);
    bool withdraw(double amount);
    bool transferTo(double amount, Client& recipient);
    void checkBalance();
    void edit_client_password();
    void edit_client_balance();
    void display();
};
#endif