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
    return ScreenTheme::choose_them(menu,6,75,31);
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
