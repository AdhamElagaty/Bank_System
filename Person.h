#include <iostream>
using namespace std;

class Person {
private:
    string id, first_name, second_name, password;
public:
    Person();
    Person(string first_name, string second_name, string password);
    Person(string id, string first_name, string second_name, string password);
};