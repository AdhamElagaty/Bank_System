#include <iostream>
#include "Person.h"
#include "Client.h"
#ifndef CLIENTMANGER_H
#define CLIENTMANGER_H
class ClientManger {
public:
    static void print_client_menu();
    static void update_password(Client* client);
};
#endif
