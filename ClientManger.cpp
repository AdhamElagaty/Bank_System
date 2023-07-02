#include "ClientManger.h"

void ClientManger::print_client_menu() {
    cout << "###################################" << endl;
    cout << "# 1. Show My Data                 #" << endl;
    cout << "# 2. Check Balance                #" << endl;
    cout << "# 3. Deposit                      #" << endl;
    cout << "# 4. Withdraw                     #" << endl;
    cout << "# 5. Transfer To Another Account  #" << endl;
    cout << "# 6. Update Password              #" << endl;
    cout << "# 7. Logout                       #" << endl;
    cout << "###################################" << endl;
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