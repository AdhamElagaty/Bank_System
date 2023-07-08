#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <sstream>
using namespace std;

class Person {
protected:
    string id, first_name, second_name, password;
public:
    Person();
    Person(string first_name, string second_name, string password);
    Person(string id, string first_name, string second_name, string password);
    bool set_name(string name);
    void set_password(string password);
    void set_id(string id);
    string get_first_name();
    string get_second_name();
    string get_name();
    string get_password();
    string get_id();

    virtual void display() = 0;
};
#endif