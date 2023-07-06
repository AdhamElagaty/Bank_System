#include "Password.h"
#include "Parser.h"

vector<string> Parser::split(string line) {
    vector<string> result;
    string item;
    stringstream ss(line);
    while (getline(ss, item, ',')) {
        result.push_back(item);
    }
    return result;
}

Client Parser::parse_to_client(string line) {
    vector<string> fields = split(line);
    Client c;
    c.set_id(fields[0]);
    c.set_name(fields[1]);
    c.set_password(Password::decrypt_password(fields[2],fields[0]));
    c.set_balance(stod(fields[3]));
    return c;
}

Employee Parser::parse_to_employee(string line) {
    vector<string> fields = split(line);
    Employee e;
    e.set_id(fields[0]);
    e.set_name(fields[1]);
    e.set_password(Password::decrypt_password(fields[2],fields[0]));
    e.set_salary(stod(fields[3]));
    return e;
}

Admin Parser::parse_to_admin(string line) {
    vector<string> fields = split(line);
    Admin a;
    a.set_id(fields[0]);
    a.set_name(fields[1]);
    a.set_password(Password::decrypt_password(fields[2],fields[0]));
    a.set_salary(stod(fields[3]));
    return a;
}
