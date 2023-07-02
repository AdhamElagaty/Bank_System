#include <iostream>
using namespace std;

class Password {
public:
    static string takePasswdFromUser();
    static string encrypt_password(string password, string id);
    static string decrypt_password(string password, string id);
};

