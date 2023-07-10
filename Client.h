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
    Client(string first_name, string second_name, string password,string phone_number, string national_id, double balance);
    Client(string id, string first_name, string second_name, string password,string phone_number, string national_id, double balance);
    bool set_balance(double balance);
    double get_balance();
    void deposit(double amount);
    bool withdraw(double amount);
    bool transferTo(double amount, Client& recipient);
    void checkBalance();
    void edit_client_balance();
    void display();
    void display_with_national_id();
    void edit_password_in_file();
};
#endif