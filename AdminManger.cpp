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
                  "# 5. List All Employee            #\n"
                  "# 6. Search for Employee          #\n"
                  "# 7. Update Password              #\n"
                  "# 8. Logout                       #\n"
                  "###################################\n";
    return ScreenTheme::choose_them(menu,8,75,31);
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
                break;
            case 6:
                break;
            case 7:
                update_password(admin);
                break;
            default:
                r = false;
                break;
        }
    } while (r);
}


