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
    string oldPass;
    int attempt = 3;
    do{
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Update Password*";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
        ScreenTheme::color_style(12);
        cout << "ESC";
        ScreenTheme::color_style(7);
        cout << "'" << endl;
        if (attempt < 3){
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t\t\t   Incorrect password :(" << endl;
            ScreenTheme::color_style(7);
            cout << "\t\t\t\t\t\t\t\t\t\t   You has ";
            ScreenTheme::color_style(12);
            cout << attempt;
            ScreenTheme::color_style(7);
            cout << " Attempt" << endl;
        }
        cout << "\t\t\t\t\t\t\t\t\t\t   Enter old password: ";
        oldPass = Password::takePasswdFromUser();
        if(oldPass == "!x!"){
            attempt = 0;
            break;
        }
        if (oldPass == client->get_password()) {
            break;
        }
        attempt--;
    } while (attempt != 0);
    if (attempt == 0){
        return;
    }
    client->set_password(Password::Enter_new_password());
    client->edit_client_password();
    ScreenTheme::color_style(2);
    cout << "\t\t\t\t\t\t\t\t\t\t   Password updated successfully :)" << endl;
    ScreenTheme::color_style(7);
}

Client *ClientManger::login(string id, string password) {
    FileManager f;
    Client* c;
    c = f.search_client(stoi(id));
    if(c != nullptr){
        if(password == c->get_id()){
            c->set_password("0");
            c->edit_client_password();
        }
        if(c->get_password() == password){
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
    cout << "\n\n\n\n\n";
    client.display_with_national_id();
    string menu = "\n#############\n"
                  "# 1. Back   #\n"
                  "#############\n";
    ScreenTheme::choose_them(menu,1,20,30);
}

void ClientManger::deposit(Client* client) {
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
            cout << "\t\t\t\t\t\t\t\t\t   Error! Invalid Amount to Deposit :(" << endl;
            ScreenTheme::color_style(7);
            er = false;
        }
        cout << "\t\t\t\t\t\t\t\t\t   Enter Your Money to Deposit : ";
        amount = ScreenTheme::take_num_input(9);
        if(amount != "!x!"){
            try {
                if (stod(amount) <= 0){
                    er = true;
                    continue;
                }
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
                r = false;
            }catch(exception){
                er = true;
            }
        } else{
            r = false;
        }
    } while (r);
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
            er = false;
        }
        cout << "\t\t\t\t\t\t\t\t\t   Enter Your Money to Withdraw : ";
        amount = ScreenTheme::take_num_input(9);
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
                er = true;
            }
        }else{
            r = false;
        }
    }while (r);
}

void ClientManger::transfer_to(Client *client){
    string client2_id, amount;
    FileManager f;
    Client* client2 = new Client();
    bool yr = true, yer = false, mr = true, mer = false;
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
        if(yer){
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t   Error! No Account with this ID :(" << endl;
            ScreenTheme::color_style(7);
            yer = false;
        }
        if(mer){
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t   Error! Invalid Amount to Transfer :(" << endl;
            ScreenTheme::color_style(7);
            mer = false;
        }
        cout << "\t\t\t\t\t\t\t\t   Enter ID of Account do you want to transfer money : ";
        client2_id = ScreenTheme::take_num_input(5);
        if (client2_id != "!x!") {
            try {
                if (client2_id == client->get_id()){
                    yer = true;
                    continue;
                }
                client2 = f.search_client(stoi(client2_id));
                if(client2 != nullptr){
                    yr = false;
                }else{
                    yer = true;
                    continue;
                }
            } catch (exception) {
                yer = true;
            }
        }else{
            break;
        }
        if(!yer) {
            cout << "\t\t\t\t\t\t\t\t   Enter Your Money to transfer : ";
            amount = ScreenTheme::take_num_input(9);
            if (amount != "!x!") {
                try {
                    if (client->transferTo(stod(amount), *client2)) {
                        system("cls");
                        Screens::header_screen();
                        cout << "\n\n";
                        client->checkBalance();
                        ScreenTheme::color_style(2);
                        cout << "\t\t\t\t\t\t\t\t      The Money has been Transfer to " << client2->get_name() << " :)";
                        ScreenTheme::color_style(7);
                        string menu = "\n#############\n"
                                      "# 1. Back   #\n"
                                      "#############\n";
                        ScreenTheme::choose_them(menu, 1, 20, 30);
                        mr = false;
                    } else {
                        mer = true;
                    }
                } catch (exception) {
                    mer = true;
                }
            } else {
                break;
            }
        }

    }while (yr || mr);
    delete client2;
}

void ClientManger::client_options(Client *client){
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
            case 4:
                transfer_to(client);
                break;
            case 5:
                update_password(client);
                break;
            default:
                r = false;
                break;
        }
    } while (r);
}
