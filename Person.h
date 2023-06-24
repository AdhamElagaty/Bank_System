#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person {
protected:
    string id, first_name, second_name, password;
public:
    Person();
    Person(string first_name, string second_name, string password);
    Person(string id, string first_name, string second_name, string password);
    void set_name(string first_name, string second_name);
    void set_password(string password);
    string get_first_name();
    string get_second_name();
    string get_name();
    string get_password();
    string get_id();
    virtual void display() = 0;
};
#endif