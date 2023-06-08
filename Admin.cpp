#include <iostream>
#include "Admin.h"
using namespace std;

Admin::Admin() {}

Admin::Admin(string id, string first_name, string second_name, string password, double salary) :
Employee(id,first_name,second_name,password,salary){}
