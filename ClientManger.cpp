#include "ScreenTheme.h"
#include "ClientManger.h"
#include "Screens.h"
#include "Password.h"

int ClientManger::print_client_menu() {
    string menu = "\n###################################\n"
                  "# 1. Show My Data                 #\n"
                  "# 2. Deposit                      #\n"
                  "# 3. Withdraw                     #\n"
                  "# 4. Transfer To Another Account  #\n"
                  "# 5. Update Password              #\n"
                  "# 6. Logout                       #\n"
                  "###################################\n";
    return ScreenTheme::choose_them(menu,6,75,31);
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
    client->set_password(newPass);
    client->edit_client_password();
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

void ClientManger::display_client_info(Client client) {
    system("cls");
    Screens::header_screen();
    cout << "\n\n";
    client.display();
    string menu = "\n#############\n"
                  "# 1. Back   #\n"
                  "#############\n";
    ScreenTheme::choose_them(menu,1,20,30);
}

void ClientManger::deposit(Client* client) {
    system("cls");
    string amount;
    Screens::header_screen();
    cout << "\n\n";
    client->checkBalance();
    cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
    ScreenTheme::color_style(12);
    cout << "ESC";
    ScreenTheme::color_style(7);
    cout << "'" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t   Enter Your Money to Deposit : ";
    amount = ScreenTheme::take_num_input();
    if(amount != "!x!"){
        try {
            client->deposit(stod(amount));
            system("cls");
            Screens::header_screen();
            cout << "\n\n";
            client->checkBalance();
            ScreenTheme::color_style(2);
            cout << "\t\t\t\t\t\t\t\t\t\tThe Amount has been Added :)";
            ScreenTheme::color_style(7);
            string menu = "\n#############\n"
                          "# 1. Back   #\n"
                          "#############\n";
            ScreenTheme::choose_them(menu,1,20,30);
        }catch(exception){
            return;
        }
    }
}

void ClientManger::withdraw(Client *client) {
    string amount;
    bool r = true, er = false;
    do {
        system("cls");
        Screens::header_screen();
        cout << "\n\n";
        client->checkBalance();
        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
        ScreenTheme::color_style(12);
        cout << "ESC";
        ScreenTheme::color_style(7);
        cout << "'" << endl;
        cout << "\n\n";
        if(er){
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t\t   Error! Invalid Amount to Withdraw :(" << endl;
            ScreenTheme::color_style(7);
        }
        cout << "\t\t\t\t\t\t\t\t\t   Enter Your Money to Deposit : ";
        amount = ScreenTheme::take_num_input();
        if (amount != "!x!") {
            try {
                if (client->withdraw(stod(amount))) {
                    system("cls");
                    Screens::header_screen();
                    cout << "\n\n";
                    client->checkBalance();
                    ScreenTheme::color_style(2);
                    cout << "\t\t\t\t\t\t\t\t\t      The Amount has been Withdraw :)";
                    ScreenTheme::color_style(7);
                    string menu = "\n#############\n"
                                  "# 1. Back   #\n"
                                  "#############\n";
                    ScreenTheme::choose_them(menu, 1, 20, 30);
                    r = false;
                }else{
                    er = true;
                    continue;
                }
            } catch (exception) {
                return;
            }
        }else{
            r = false;
        }
    }while (r);
}

bool ClientManger::client_options(Client *client){
    int choice;
    bool r = true;
    do{
        system("cls");
        Screens::header_screen();
        choice = print_client_menu();
        switch (choice) {
            case 1:
                display_client_info(*client);
                break;
            case 2:
                deposit(client);
                break;
            case 3:
                withdraw(client);
                break;
            case 6:
                r = false;
                break;
        }
    } while (r);
    delete client;
}
