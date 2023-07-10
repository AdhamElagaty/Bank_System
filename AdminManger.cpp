#include "ScreenTheme.h"
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
