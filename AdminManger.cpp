#include "ScreenTheme.h"
#include "FilesHelper.h"
#include "Screens.h"
#include "AdminManger.h"

int AdminManger::print_admin_menu() {
    string menu = "\n###################################\n"
                  "# 1. Show My Data                 #\n"
                  "# 2. Add New Client               #\n"
                  "# 3. List All Client              #\n"
                  "# 4. Search for Client            #\n"
                  "# 5. Add New Employee             #\n"
                  "# 6. List All Employee            #\n"
                  "# 7. Search for Employee          #\n"
                  "# 8. Update Password              #\n"
                  "# 9. Logout                       #\n"
                  "###################################\n";
    return ScreenTheme::choose_them(menu,9,75,31);
}

Admin *AdminManger::login(string id, string password) {
    FileManager f;
    Admin* a;
    a = FilesHelper::search_admin(stoi(id));
    if(a != nullptr){
        if(a->get_password() == password){
            return a;
        }else{
            return nullptr;
        }
    } else{
        return nullptr;
    }
}

void AdminManger::display_admin_info(Admin admin) {
    system("cls");
    Screens::header_screen();
    cout << "\n\n\n\n\n";
    admin.display_with_national_id();
    string menu = "\n#############\n"
                  "# 1. Back   #\n"
                  "#############\n";
    ScreenTheme::choose_them(menu,1,20,30);
}

void AdminManger::add_new_employee(Admin *admin) {
    Employee e;
    string FName, SName, Salary, phone_number, national_id;
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New Employee";
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
    if(!e.set_name(FName + " " + SName)){
        return;
    }
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New Employee";
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
    if(!e.set_phone_number(phone_number)){
        return;
    }
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New Employee";
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
    if(!e.set_national_id(national_id+"x")){
        return;
    }
    system("cls");
    Screens::header_screen();
    ScreenTheme::color_style(11);
    cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
    ScreenTheme::color_style(7);
    cout << "Add New Employee";
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
    cout << "\t\t\t\t\t\t\t\t\t  to Add New Employee do you need set Salary more than 5000 : ";
    Salary = ScreenTheme::take_num_input(10);
    if (Salary == "!x!"){
        return;
    }
    if(!e.set_salary(stod(Salary))){
        return;
    }
    admin->add_employee(e);
    system("cls");
    display_employee_info(e);
}

void AdminManger::list_all_admin(Admin *admin) {
    int choice;
    do {
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "All Employees";
        ScreenTheme::color_style(11);
        cout << " #$#$#$" << endl;
        ScreenTheme::color_style(7);
        cout << "\n\n";
        admin->list_employee();
        string menu = "\n################################\n"
                      "# 1. Add New Employee          #\n"
                      "# 2. Search for Employee       #\n"
                      "# 3. Back                      #\n"
                      "################################\n";
        choice = ScreenTheme::choose_them(menu,3,27,35);
        switch (choice) {
            case 1:
                add_new_employee(admin);
                break;
            case 2:
                search_for_employee(admin);
                break;
            default:
                return;
        }
    } while (true);
}

void AdminManger::search_for_employee(Admin *admin) {
    string id;
    Employee* e;
    bool r = false;
    do {
        system("cls");
        Screens::header_screen();
        ScreenTheme::color_style(11);
        cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
        ScreenTheme::color_style(7);
        cout << "Search for Employee";
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
        e = admin->search_employee(stoi(id));
        if (e != nullptr){
            int choice;
            do {
                system("cls");
                Screens::header_screen();
                ScreenTheme::color_style(11);
                cout << "\n\t\t\t\t\t\t\t\t\t       $#$#$# ";
                ScreenTheme::color_style(7);
                cout << "Employee Information";
                ScreenTheme::color_style(11);
                cout << " #$#$#$" << endl;
                ScreenTheme::color_style(7);
                cout << "\n\n";
                e->display();
                int r;
                string menu = "\n#####################################\n"
                              "# 1. Edit Salary                    #\n"
                              "# 2. Edit Employee Information      #\n"
                              "# 3. Back                           #\n"
                              "#####################################\n";
                choice = ScreenTheme::choose_them(menu,3,75,40);
                switch (choice) {
                    case 1: {
                        break;
                    }
                    case 2: {
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

void AdminManger::admin_options(Admin *admin) {
    int choice;
    bool r = true;
    do{
        system("cls");
        Screens::header_screen();
        choice = print_admin_menu();
        switch (choice) {
            case 1:
                display_admin_info(*admin);
                break;
            case 2:
                add_new_client(admin);
                break;
            case 3:
                list_all_client(admin);
                break;
            case 4:
                search_for_client(admin);
                break;
            case 5:
                add_new_employee(admin);
                break;
            case 6:
                list_all_admin(admin);
                break;
            case 7:
                search_for_employee(admin);
                break;
            case 8:
                update_password(admin);
                break;
            default:
                r = false;
                break;
        }
    } while (r);
}


