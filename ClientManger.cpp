#include "ScreenTheme.h"
#include "ClientManger.h"
#include "Password.h"

int ClientManger::print_client_menu() {
    string menu = "\n###################################\n"
                  "# 1. Show My Data                 #\n"
                  "# 2. Check Balance                #\n"
                  "# 3. Deposit                      #\n"
                  "# 4. Withdraw                     #\n"
                  "# 5. Transfer To Another Account  #\n"
                  "# 6. Update Password              #\n"
                  "# 7. Logout                       #\n"
                  "###################################\n";
    return ScreenTheme::choose_them(menu,7,75,31);
}

void ClientManger::update_password(Client *client) {
    string oldPass, newPass, confirmPass;
    cout << "Enter old password: ";
    cin >> oldPass;
    if (oldPass != client->get_password()) {
        cout << "Incorrect password :(" << endl;
        return;
    }
    cout << "Enter new password: ";
    cin >> newPass;
    cout << "Confirm new password: ";
    cin >> confirmPass;
    if (newPass != confirmPass) {
        cout << "Passwords do not match :(" << endl;
        return;
    }
    client->edit_client(stoi(client->get_id()), newPass);
    client->set_password(newPass);
    cout << "Password updated successfully :)" << endl;
}

Client *ClientManger::login(string id, string password) {
    FileManager f;
    Client* c = new Client();
    c = f.search_client(stoi(id));
    if(c != nullptr){
        string pass = Password::decrypt_password(c->get_password(),id);
        c->set_password(pass);
        if(pass == password){
            return c;
        }else{
            return nullptr;
        }
    } else{
        return nullptr;
    }
}
