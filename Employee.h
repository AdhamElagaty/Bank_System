#include <iostream>
#include "Person.h"
using namespace std;

class Employee : public Person{
protected:
    double salary;
public:
    Employee();
    Employee(string id, string first_name, string second_name, string password, double salary);
    void set_salary(double salary);
    double get_salary();
    void display();
};
