#include <iostream>
#include "FilesHelper.h"
using namespace std;

int main() {
    Client c1("Adham","Hassan","123456789",2000), c2("Saif","Sayed","123456789",2500);
    FilesHelper::saveClient(c1);
    FilesHelper::saveClient(c2);
    vector<Client> c;
    c = FilesHelper::getClients();
    for (int i = 0; i < c.size(); ++i) {
        c[i].display();
    }
    FilesHelper::clearFile("Clients.txt","Last_id_Clients.txt");
    return 0;
}
