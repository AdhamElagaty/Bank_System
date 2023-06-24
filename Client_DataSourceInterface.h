#ifndef CLIENT_DATASOURCEINTERFACE_H
#define CLIENT_DATASOURCEINTERFACE_H
#include <vector>
#include "Client.h"
using namespace std;

class Client;

class Client_DataSourceInterface {
public:
    virtual void add_client() = 0;
    virtual vector<Client> get_all_clients() = 0;
    virtual void remove_all_clients() = 0;
};
#endif