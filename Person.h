#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <sstream>
using namespace std;

class Person {
protected:
    string id, first_name, second_name, password, phone_number, national_id;
public:
    Person();
    Person(string first_name, string second_name, string password, string phone_number, string national_id);
    Person(string id, string first_name, string second_name, string password, string phone_number, string national_id);
    bool set_name(string name);
    void set_password(string password);
    void set_id(string id);
    bool set_phone_number(string phone_number);
    bool set_national_id(string national_id);
    string get_first_name();
    string get_second_name();
    string get_name();
    string get_password();
    string get_id();
    string get_phone_number();
    string get_national_id();
    virtual void display() = 0;
    virtual void display_with_national_id() = 0;
};
#endif