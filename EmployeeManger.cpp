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

int EmployeeManger::check_national_id(Person *person){
    string national_id = ScreenTheme::take_num_input(14);
    if(national_id == "!x!"){
        return 3;
    }
    if((person->get_national_id() == national_id)){
        return 1;
    }
    return 0;
}

Employee *EmployeeManger::login(string id, string password) {
    FileManager f;
    Employee* e;
    e = f.search_employee(stoi(id));
    if(e != nullptr){
        if(password == e->get_id()){
            e->set_password("0");
            e->edit_password_in_file();
        }
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
    cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
    ScreenTheme::color_style(12);
    cout << "ESC";
    ScreenTheme::color_style(7);
    cout << "'" << endl;
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
    cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
    ScreenTheme::color_style(12);
    cout << "ESC";
    ScreenTheme::color_style(7);
    cout << "'" << endl;
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
    cout << "\t\t\t\t\t\t\t\t\t\t   To Cancel Press '";
    ScreenTheme::color_style(12);
    cout << "ESC";
    ScreenTheme::color_style(7);
    cout << "'" << endl;
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
                return;
        }
    } while (true);
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
                ScreenTheme::color_style(11);
                cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
                ScreenTheme::color_style(7);
                cout << "client Information";
                ScreenTheme::color_style(11);
                cout << " #$#$#$" << endl;
                ScreenTheme::color_style(7);
                cout << "\n\n";
                c->display();
                int r;
                string menu = "\n#####################################\n"
                              "# 1. Deposit                        #\n"
                              "# 2. Withdraw                       #\n"
                              "# 3. Transfer To Another Account    #\n"
                              "# 4. Edite Client Information       #\n"
                              "# 5. Back                           #\n"
                              "#####################################\n";
                choice = ScreenTheme::choose_them(menu,5,75,40);
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
                        r = check_national_id(c);
                        if(r == 1){
                            deposit(c);
                        }else if(r == 0){
                            ScreenTheme::color_style(12);
                            cout << "\t\t\t\t\t\t\t\t\t   Invalid National ID :( " << endl;
                            ScreenTheme::color_style(7);
                            string menu2 = "\n#############\n"
                                          "# 1. Back   #\n"
                                          "#############\n";
                            ScreenTheme::choose_them(menu2,1,20,30);
                        } else{
                            continue;
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
                        r = check_national_id(c);
                        if(r == 1){
                            withdraw(c);
                        }else if(r == 0){
                            ScreenTheme::color_style(12);
                            cout << "\t\t\t\t\t\t\t\t\t   Invalid National ID :( " << endl;
                            ScreenTheme::color_style(7);
                            string menu2 = "\n#############\n"
                                           "# 1. Back   #\n"
                                           "#############\n";
                            ScreenTheme::choose_them(menu2,1,20,30);
                        } else{
                            continue;
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
                        r = check_national_id(c);
                        if(r == 1){
                            transfer_to(c);
                        }else if(r == 0){
                            ScreenTheme::color_style(12);
                            cout << "\t\t\t\t\t\t\t\t\t   Invalid National ID :( " << endl;
                            ScreenTheme::color_style(7);
                            string menu2 = "\n#############\n"
                                           "# 1. Back   #\n"
                                           "#############\n";
                            ScreenTheme::choose_them(menu2,1,20,30);
                        } else{
                            continue;
                        }
                        break;
                    }
                    case 4:
                    {
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
                        r = check_national_id(c);
                        if(r == 1){
                            edite_client_info(employee,c);
                        }else if(r == 0){
                            ScreenTheme::color_style(12);
                            cout << "\t\t\t\t\t\t\t\t\t   Invalid National ID :( " << endl;
                            ScreenTheme::color_style(7);
                            string menu2 = "\n#############\n"
                                           "# 1. Back   #\n"
                                           "#############\n";
                            ScreenTheme::choose_them(menu2,1,20,30);
                        } else{
                            continue;
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

void  EmployeeManger::edite_name_of_client(Employee *employee, Client *client) {
    string FName, SName;
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Edit Client Name";
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
    if(!client->set_name(FName + " " + SName)){
        return;
    }
    employee->edit_client(stoi(client->get_id()),client->get_first_name(),client->get_second_name(),client->get_password(),client->get_phone_number(),client->get_balance());
}

void EmployeeManger::edite_phone_number_of_client(Employee *employee, Client *client) {
    string phone_number;
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Edit Client Phone Number";
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
    cout << "\t\t\t\t\t\t\t\t\t  Enter Phone Number : ";
    phone_number = ScreenTheme::take_num_input(11);
    if (phone_number == "!x!"){
        return;
    }
    if(!client->set_phone_number(phone_number)){
        return;
    }
    employee->edit_client(stoi(client->get_id()),client->get_first_name(),client->get_second_name(),client->get_password(),client->get_phone_number(),client->get_balance());
}

void EmployeeManger::reset_password_of_client(Employee *employee, Client *client) {
    int r;
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
    r = check_national_id(client);
    if(r == 1){
        employee->edit_client(stoi(client->get_id()),client->get_first_name(),client->get_second_name(),client->get_id()+"00000000",client->get_phone_number(),client->get_balance());
        ScreenTheme::color_style(2);
        cout << "\t\t\t\t\t\t\t\t\t   Password Reset Successfully :) " << endl;
        ScreenTheme::color_style(7);
        cout << "\t\t\t\t\t\t\t\t\t   Now Client ' " << client->get_first_name() << " ' Can Create New Password." << endl;
    }else if (r == 0){
        ScreenTheme::color_style(12);
        cout << "\t\t\t\t\t\t\t\t\t   Invalid National ID :( " << endl;
        ScreenTheme::color_style(7);
    }else{
        return;
    }
    string menu = "\n#############\n"
                  "# 1. Back   #\n"
                  "#############\n";
    ScreenTheme::choose_them(menu,1,20,30);
}

void EmployeeManger::edite_client_info(Employee* employee, Client* client){
    int choice;
    do{
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t   $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Edite client Information";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        client->display();
        cout << "\n\n";
        string menu = "\n##################################\n"
                      "# 1. Edite Name                  #\n"
                      "# 2. Edite Phone Number          #\n"
                      "# 3. Reset Password              #\n"
                      "# 4. Back                        #\n"
                      "##################################\n";
        choice = ScreenTheme::choose_them(menu,4,75,40);
        switch (choice) {
            case 1:
                edite_name_of_client(employee,client);
                break;
            case 2:
                edite_phone_number_of_client(employee,client);
                break;
            case 3:
                reset_password_of_client(employee,client);
                break;
            default:
                return;

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
