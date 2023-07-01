#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser {
private:
    static vector<string> split(string line);
public:
    static Client parse_to_client(string line);
    static Employee parse_to_employee(string line);
    static Admin parse_to_admin(string line);
};
#endif

