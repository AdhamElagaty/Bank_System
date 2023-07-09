#include "ScreenTheme.h"
#include "Screens.h"
#include "Password.h"
#include "EmployeeManger.h"

int EmployeeManger::print_employee_menu() {
    string menu = "\n###################################\n"
                  "# 1. Show My Data                 #\n"
                  "# 2. Add New Client               #\n"
                  "# 3. List All Client              #\n"
                  "# 4. Search for Client            #\n"
                  "# 5. Update Password              #\n"
                  "# 6. Logout                       #\n"
                  "###################################\n";
    return ScreenTheme::choose_them(menu,6,75,31);
}

bool EmployeeManger::check_national_id(Client client){
    string national_id = ScreenTheme::take_num_input(14);
    return (client.get_national_id() == national_id);
}

void EmployeeManger::update_password(Employee* employee) {
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
        if (oldPass == employee->get_password()) {
            break;
        }
        attempt--;
    } while (attempt != 0);
    if (attempt == 0){
        return;
    }
    employee->set_password(Password::Enter_new_password());
    employee->edit_employee_password();
    ScreenTheme::color_style(2);
    cout << "\t\t\t\t\t\t\t\t\t\t   Password updated successfully :)" << endl;
    ScreenTheme::color_style(7);
}

Employee *EmployeeManger::login(string id, string password) {
    FileManager f;
    Employee* e;
    e = f.search_employee(stoi(id));
    if(e != nullptr){
        if(e->get_password() == password){
            return e;
        }else{
            return nullptr;
        }
    } else{
        return nullptr;
    }
}

void EmployeeManger::display_employee_info(Employee employee) {
    system("cls");
    Screens::header_screen();
    cout << "\n\n\n\n\n";
    employee.display_with_national_id();
    string menu = "\n#############\n"
                  "# 1. Back   #\n"
                  "#############\n";
    ScreenTheme::choose_them(menu,1,20,30);
}

void EmployeeManger::add_new_client(Employee* employee) {
    Client c;
    string FName, SName, Balance, phone_number, national_id;
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New client";
    ScreenTheme::color_style(11);
    cout << " #$#$#$" << endl;
    ScreenTheme::color_style(7);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
    ScreenTheme::color_style(12);
    cout << "ESC";
    ScreenTheme::color_style(7);
    cout << "'" << endl;
    ScreenTheme::color_style(7);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t\t  Enter First Name : ";
    FName = ScreenTheme::take_alphabet_input(12);
    if (FName == "!x!"){
        return;
    }
    cout << "\t\t\t\t\t\t\t\t\t  Enter Second Name : ";
    SName = ScreenTheme::take_alphabet_input(12);
    if (SName == "!x!"){
        return;
    }
    if(!c.set_name(FName + " " + SName)){
        return;
    }
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New client";
    ScreenTheme::color_style(11);
    cout << " #$#$#$" << endl;
    ScreenTheme::color_style(7);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t\t  Enter Phone Number : ";
    phone_number = ScreenTheme::take_num_input(11);
    if (phone_number == "!x!"){
        return;
    }
    if(!c.set_phone_number(phone_number)){
        return;
    }
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New client";
    ScreenTheme::color_style(11);
    cout << " #$#$#$" << endl;
    ScreenTheme::color_style(7);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t\t  Enter National ID : ";
    national_id = ScreenTheme::take_num_input(14);
    if (national_id == "!x!"){
        return;
    }
    if(!c.set_national_id(national_id+"x")){
        return;
    }
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New client";
    ScreenTheme::color_style(11);
    cout << " #$#$#$" << endl;
    ScreenTheme::color_style(7);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t\t\t\t  to Open Account do you need deposit more than 1500 : ";
    Balance = ScreenTheme::take_num_input(10);
    if (Balance == "!x!"){
        return;
    }
    if(!c.set_balance(stod(Balance))){
        return;
    }
    employee->add_client(c);
    system("cls");
    display_client_info(c);
}

void EmployeeManger::list_all_client(Employee *employee) {
    int choice;
    bool r = true;
    do {
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "All client";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        employee->list_client();
        string menu = "\n################################\n"
                      "# 1. Add New Client            #\n"
                      "# 2. Search for Client         #\n"
                      "# 3. Back                      #\n"
                      "################################\n";
        choice = ScreenTheme::choose_them(menu,3,27,35);
        switch (choice) {
            case 1:
                add_new_client(employee);
                break;
            case 2:
                search_for_client(employee);
                break;
            default:
                r = false;
                break;
        }
    } while (r);
}

void EmployeeManger::search_for_client(Employee *employee) {
    string id;
    Client* c;
    bool r = false;
    do {
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Search for client";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
        ScreenTheme::color_style(12);
        cout << "ESC";
        ScreenTheme::color_style(7);
        cout << "'" << endl;
        cout << "\n\n";
        if (r){
            ScreenTheme::color_style(12);
            cout << "\t\t\t\t\t\t\t\t\t   Error! Invalid ID;" << endl;
            cout << "\t\t\t\t\t\t\t\t\t   ---> No Client with this ID :(" << endl;
            ScreenTheme::color_style(7);
        }
        cout << "\t\t\t\t\t\t\t\t\t   Enter ID to Search : ";
        id = ScreenTheme::take_num_input(5);
        if(id == "!x!"){
            return;
        }
        c = employee->search_client(stoi(id));
        if (c != nullptr){
            int choice;
            do {
                system("cls");
                Screens::header_screen();
                cout << "\n\n";
                c->display();
                string menu = "\n#####################################\n"
                              "# 1. Deposit                        #\n"
                              "# 2. Withdraw                       #\n"
                              "# 3. Transfer To Another Account    #\n"
                              "# 4. Edite Client Information       #\n"
                              "# 5. Back                           #\n"
                              "#####################################\n";
                choice = ScreenTheme::choose_them(menu,5,75,37);
                switch (choice) {
                    case 1: {
                        system("cls");
                        Screens::header_screen();
                        cout << "\n\n";
                        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
                        ScreenTheme::color_style(12);
                        cout << "ESC";
                        ScreenTheme::color_style(7);
                        cout << "'" << endl;
                        cout << "\n\n";
                        cout << "\t\t\t\t\t\t\t\t\t   Enter National ID to Deposit : ";
                        if(check_national_id(*c)){
                            deposit(c);
                        }
                        break;
                    }
                    case 2: {
                        system("cls");
                        Screens::header_screen();
                        cout << "\n\n";
                        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
                        ScreenTheme::color_style(12);
                        cout << "ESC";
                        ScreenTheme::color_style(7);
                        cout << "'" << endl;
                        cout << "\n\n";
                        cout << "\t\t\t\t\t\t\t\t\t   Enter National ID to Withdraw : ";
                        if (check_national_id(*c)) {
                            withdraw(c);
                        }
                        break;
                    }
                    case 3:{
                        system("cls");
                        Screens::header_screen();
                        cout << "\n\n";
                        cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
                        ScreenTheme::color_style(12);
                        cout << "ESC";
                        ScreenTheme::color_style(7);
                        cout << "'" << endl;
                        cout << "\n\n";
                        cout << "\t\t\t\t\t\t\t\t\t   Enter National ID to Transfer to : ";
                        if(check_national_id(*c)){
                            transfer_to(c);
                        }
                        break;
                    }
                    default:
                        return;
                }
            } while (true);
        }else{
            r = true;
            continue;
        }
    } while (true);
}

void EmployeeManger::employee_options(Employee* employee) {
    int choice;
    bool r = true;
    do{
        system("cls");
        Screens::header_screen();
        choice = print_employee_menu();
        switch (choice) {
            case 1:
                display_employee_info(*employee);
                break;
            case 2:
                add_new_client(employee);
                break;
            case 3:
                list_all_client(employee);
                break;
            case 4:
                search_for_client(employee);
                break;
            case 5:
                update_password(employee);
                break;
            default:
                r = false;
                break;
        }
    } while (r);
}
