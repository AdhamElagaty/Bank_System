#include <iostream>
#include "Person.h"
#include "FileManager.h"
#include "Client.h"
#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
class ClientManger {
public:
    static int print_client_menu();
    static void update_password(Client* client);
    static Client* login(string id, string passw0rd);
};
#endif
