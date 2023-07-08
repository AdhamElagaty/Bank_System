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
                  "# 5. Edite Client Data            #\n"
                  "# 6. Update Password              #\n"
                  "# 7. Logout                       #\n"
                  "###################################\n";
    return ScreenTheme::choose_them(menu,7,75,31);
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
    cout << "\n\n";
    employee.display();
    string menu = "\n#############\n"
                  "# 1. Back   #\n"
                  "#############\n";
    ScreenTheme::choose_them(menu,1,20,30);
}

void EmployeeManger::Add_new_client(Employee* employee) {
    Client c;
    string FName, SName, Balance;
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
    cout << "\t\t\t\t\t\t\t\t\t  Enter First Name : ";
    FName = ScreenTheme::take_alphabet_input();
    if (FName == "!x!"){
        return;
    }
    cout << "\t\t\t\t\t\t\t\t\t  Enter Second Name : ";
    SName = ScreenTheme::take_alphabet_input();
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
    cout << "\t\t\t\t\t\t\t\t\t  to Open Account do you need deposit more than 1500 : ";
    Balance = ScreenTheme::take_num_input();
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
                Add_new_client(employee);
                break;
            case 3:
//                withdraw(client);
                break;
            case 4:
//                transfer_to(client);
                break;
            case 6:
                update_password(employee);
                break;
            default:
                r = false;
                break;
        }
    } while (r);
}
