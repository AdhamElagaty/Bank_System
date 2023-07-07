#include <iostream>
#include "Person.h"
#include "FileManager.h"
#include "Client.h"
#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
class ClientManger {
private:
    static void display_client_info(Client client);
    static void deposit(Client* client);
    static void withdraw(Client* client);
    static void transfer_to(Client *client);
    static void update_password(Client* client);
public:
    static int print_client_menu();
    static Client* login(string id, string password);
    static bool client_options(Client* client);
};
#endif
