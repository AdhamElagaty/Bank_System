#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ScreenTheme.h"
#include "Screens.h"
using namespace std;

void Screens::view_date_and_time() {
    time_t now = time(nullptr);
    string  date_and_time = ctime(&now);
    ScreenTheme::color_style(4);
    cout << "\t\t\t\t\t\t\t\t\t\t" << date_and_time << endl;
}

void Screens::loading_screen() {
    system("cls");
    ScreenTheme::color_style(14);
    cout << "\n\n";
    cout << "\t\t\t\t\t\t           G############################BBBBBBBB############################G           " << endl;
    cout << "\t\t\t\t\t\t         .?B?!!!!!!!!!!!!!!!!!!!!!!!!!!?J5GBBG5J?!!!!!!!!!!!!!!!!!!!!!!!!!!?B7.         " << endl;
    cout << "\t\t\t\t\t\t       .?#@.                       .!YB###GGGG###BY!.                        @#?.       " << endl;
    cout << "\t\t\t\t\t\t     :J&@G!                      ~P&@BJ          JG@&P~                      !G@&J:     " << endl;
    cout << "\t\t\t\t\t\t   :Y&@P~                      ^G@&J:     ";
    ScreenTheme::color_style(10);
    cout << ".$$.";
    ScreenTheme::color_style(14);
    cout <<"     ^J&@P^                      ~P@&Y^   " << endl;
    cout << "\t\t\t\t\t\t ^5&@G!:::::::::              ?@@Y.       ";
    ScreenTheme::color_style(10);
    cout <<"/$$\\";
    ScreenTheme::color_style(14);
    cout << "       .Y@@?              :::::::::!G@&5^ " << endl;
    cout << "\t\t\t\t\t\t~#@@&#########&&7            ?@@7     ";
    ScreenTheme::color_style(2);
    cout << "$$$$$$$$$$$$$";
    ScreenTheme::color_style(14);
    cout << "    7@@?            7&&#########&&@#~" << endl;
    cout << "\t\t\t\t\t\t              &@J           ^&@J     ";
    ScreenTheme::color_style(2);
    cout << "$$$  ";
    ScreenTheme::color_style(10);
    cout << "|$$|";
    ScreenTheme::color_style(14);
    cout << "          J@&^           J@&              " << endl;
    cout << "\t\t\t\t\t\t              &@J           J@#:     ";
    ScreenTheme::color_style(2);
    cout << "$$$";
    ScreenTheme::color_style(10);
    cout << "  |$$|";
    ScreenTheme::color_style(14);
    cout << "          :#@J           J@&              " << endl;
    cout << "\t\t\t\t\t\t!@@&&&&&&&&&&&&&7           5@B.      ";
    ScreenTheme::color_style(2);
    cout << "$$$$$$$$$$$";
    ScreenTheme::color_style(14);
    cout << "       .B@5           7&&&&&&&&&&&&&@@!" << endl;
    cout << "\t\t\t\t\t\t7@&                         ?@&:          ";
    ScreenTheme::color_style(10);
    cout << "|$$|";
    ScreenTheme::color_style(2);
    cout <<" $$$";
    ScreenTheme::color_style(14);
    cout << "      :&@?                         &@7" << endl;
    cout << "\t\t\t\t\t\t7@&                         ?@@5          ";
    ScreenTheme::color_style(10);
    cout << "|$$|";
    ScreenTheme::color_style(2);
    cout <<" $$$";
    ScreenTheme::color_style(14);
    cout << "      Y@@                          &@7" << endl;
    cout << "\t\t\t\t\t\t~@@@##################&@@#####@@J    ";
    ScreenTheme::color_style(2);
    cout << "$$$$$$$$$$$$$";
    ScreenTheme::color_style(14);
    cout << "     J@@#####@@&##################@@@~" << endl;
    cout << "\t\t\t\t\t\t !&@Y                !&@Y     !#@P^       ";
    ScreenTheme::color_style(10);
    cout << "\\$$/";
    ScreenTheme::color_style(14);
    cout << "       ^P@#!     Y@&!                Y@&!" << endl;
    cout << "\t\t\t\t\t\t  !&@5              ?&@Y       :Y@@P!.    ";
    ScreenTheme::color_style(10);
    cout << ".$$.";
    ScreenTheme::color_style(14);
    cout << "    .!P@@Y:       Y@&?              5@&!  " << endl;
    cout << "\t\t\t\t\t\t   ~GB#@@#BBBBBBB@@&BB?          :JB@#P?!^.  .^!?P#@BJ:          ?BB&@@BBBBBBB#@@#BG~   " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                ^5@@&&####&&@@5^                Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 7@&^:~!!~:^&@7                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@?                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      ~@@!      .#@Y                 ?@&:      :&@7                 Y@#.      !@@~      " << endl;
    cout << "\t\t\t\t\t\t      7@@?:^^^^:^#@5                 J@&~:^^^^:~&@J                 5@#^:^^^^:?@@7      " << endl;
    cout << "\t\t\t\t\t\t   J&&#&&&#######&&&&@P.          5@&&&&#######&&&&&@Y          .P@&&&&#######&&&#&&J   " << endl;
    cout << "\t\t\t\t\t\t  J@&                G@G:       .5@#~               #@5.       :G@G^              !&@J  " << endl;
    cout << "\t\t\t\t\t\t Y@@                 !#@B~~~~~~~P@&?^               ?&@P~~~~~~~B@#!^              ^J@@Y " << endl;
    cout << "\t\t\t\t\t\t!@@#####################&#######&######################&#######&#####################@@7" << endl;
    cout << "\t\t\t\t\t\t7@&^ .............................................................................. ^&@7" << endl;
    cout << "\t\t\t\t\t\t7@@?                                                                                ?@@7" << endl;
    cout << "\t\t\t\t\t\t~BB##################################################################################BB~" << endl;
    cout << "\t\t\t\t\t\t                                                                                        " << endl;
    ScreenTheme::color_style(13);
    bank_name();
    ScreenTheme::color_style(15);
    cout << "\n\n\t\t\t\t\t\t\t\tLoading  ";
    char x = (char)219;
    ScreenTheme::color_style(8);
    for (int i = 0; i < 45; ++i) {
        Sleep(70);
        cout << x;
    }
    system("cls");
}

void Screens::bank_name() {
    cout << "\t\t\t\t\t\t            .%%%#.  %%=    -%%#####.   =++:    =++.   :++.   -++     .=+**=:            " << endl;
    cout << "\t\t\t\t\t\t            .%%%#.  %%=    -%%          *%%= :#%#:    -%%:   +%%.   .#%#+*%#:           " << endl;
    cout << "\t\t\t\t\t\t            .%%%%#- %%=    -%%           =%%*%%*.     -%%:   +%%.   :%%*                " << endl;
    cout << "\t\t\t\t\t\t            .%%+-%%+%%=    -%%%%%%+       =%%%#       -%%:   +%%.    .+#%%%*:           " << endl;
    cout << "\t\t\t\t\t\t            .%%+ :#%%%=    -%%           +%%+#%#.     :%%-   +%%.        .*%%           " << endl;
    cout << "\t\t\t\t\t\t            .%%+  .*%%=    -%%#####.   .#%%- .*%%-     +%%#*#%%=    =#%#*#%%*           " << endl;
}

void Screens::welcome() {
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    ScreenTheme::color_style(3);
    cout << "\t\t\t-===.     ====.     ===-    -%%%%%%%%%#      :===.               .:-==-:              .:-==-:          .===-        :===:      -%%%%%%%%%#" << endl;
    Sleep(50);
    cout << "\t\t\t:%%%+    =%%%%*    =%%%-    -%%%#******     =%%%:            .=#%%%%%%%%*-        .+#%%%%%%%%*-       :%%%%*.     -%%%%+      -%%%#******" << endl;
    Sleep(50);
    cout << "\t\t\t *%%%.  .#%%%%%:   #%%*     -%%%             =%%%:           =%%%%*=--+#%%%#      =%%%%*=--+#%%%#.     :%%%%%#.   =%%%%%+      -%%%       " << endl;
    Sleep(50);
    cout << "\t\t\t :%%%*  +%%%%%%*  =%%%-     -%%%             =%%%:          -%%%*.     .+#+:     -%%%*.      -#%%#     :%%%%%%#: +%%%%%%+      -%%%       " << endl;
    Sleep(50);
    cout << "\t\t\t  +%%%::%%%+=%%%- #%%*      -%%%%%%%%%=      =%%%:          *%%%.                *%%#         =%%%:    :%%%**%%%#%%%=%%%+      -%%%%%%%%%=" << endl;
    Sleep(50);
    cout << "\t\t\t  .#%%**%%#  #%%#+%%%.      -%%%             =%%%:          *%%%:                *%%%.        +%%%:    :%%%= +%%%%#: #%%+      -%%%       " << endl;
    Sleep(50);
    cout << "\t\t\t   =%%%%%%=  -%%%%%%+       -%%%             =%%%:          :%%%%=     .+#+:     :%%%#-     .+%%%*     :%%%=  =%%#.  %%%+      -%%%       " << endl;
    Sleep(50);
    cout << "\t\t\t   .#%%%%#    *%%%%%.       -%%%#******:     =%%%#******     .*%%%%#**#%%%%+      :*%%%%#**#%%%#=      :%%%=   :=   .#%%+      -%%%#******" << endl;
    Sleep(50);
    cout << "\t\t\t    =%%%%:    .#%%%+        -%%%%%%%%%%-     =%%%%%%%%%%       :=*%%%%%#*-.         :+#%%%%%#*-        :%%%=        .#%%+      -%%%%%%%%%%" << endl;
    Sleep(50);
    cout << "\t\t\t                                                                                                                                          " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                                                                                          " << endl;
    Sleep(50);
    ScreenTheme::color_style(13);
    cout << "\t\t\t                           :%%%%-   +%%*      %%%%%%%%%%    -*%%%-   +%%#:.    -%%#     #%%-      .-=++=-                                 " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%%-   +%%*      %%%            *%%%-   +%%#:     -%%#     #%%-     =%%%%%%%%=                               " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%%%+  +%%*      %%%             =%%%=.*%%#.      -%%#     #%%-     %%%+   *=.                               " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%#%%*.+%%*      %%%%%%%%*        -#%%%%%+        -%%#     #%%-     +%%%*=-:                                 " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%.+%%##%%*      %%%%%%%%*         =%%%%#.        -%%#     #%%-      :=*#%%%#=                               " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%. -%%%%%*      %%%              +%%%#%%#:       -%%#     #%%-          .-#%%-                              " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%.  .#%%%*      %%%            .*%%#: =%%%=      .#%%#===*%%#.    :#%%+  +%%%-                              " << endl;
    Sleep(50);
    cout << "\t\t\t                           :%%%.    *%%*      %%%%%%%%%%    -%%%*.   -%%%+       =#%%%%%#=.      :*%%%%%%*-                               " << endl;
    Sleep(50);
    ScreenTheme::color_style(5);
    cout << "\t\t\t                                                                              ****+.         *        .*-   +=     :*  .*=                " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              #     )       %=#       .%%+  **     :%.=#-                 " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              # ++*<       #+ +#      .%-=#-**     :%##*                  " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              #     )     +#+++#+     .%:  #%*     :%: +#.                " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              +++++`     .+.   .+.     +.   ==     .+   -+                " << endl;
    Sleep(500);
    system("cls");
}

void Screens::header_screen() {
    view_date_and_time();
    cout << "\n\n";
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "                       %%%%%#*+=:             " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "                       ==+*#%%%%%%#+          " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "                       --:.  .:=*%%*.         " << endl;
    ScreenTheme::color_style(13);
    cout << "    -***=     :***.      :*********=     .+***:      =***-      =**=     .***-       .=*###*+:                                   ";
    ScreenTheme::color_style(8);
    cout << "                       %%%%%#*=:  +%";
    ScreenTheme::color_style(7);
    cout << "%*-.      " << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%%*.   =%%%.      :%%%%%%%%%*      .*%%%=   .#%%%=       *%%*     .%%%=      =%%%%%%%%%#.                                 ";
    ScreenTheme::color_style(8);
    cout << "                       -=+*#%%%%#.-";
    ScreenTheme::color_style(7);
    cout << "+%%%%+.    " << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%%%#:  =%%%.      :%%%=.....         +%%%*.-%%%#:        *%%*     .%%%=      #%%#.  :+=.                                  ";
    ScreenTheme::color_style(8);
    cout << "              .:-=+++++==-.  .-*%+";
    ScreenTheme::color_style(7);
    cout << "-  =#%%%+.  " << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%%%%%- =%%%.      :%%%*=====          -%%%%%%%*.         *%%*     .%%%=      +%%%*=-.                                     ";
    ScreenTheme::color_style(8);
    cout << "          :+#%%%%%%%%%%%%%%%#+.+";
    ScreenTheme::color_style(7);
    cout << "%%%#=  -#%%%- " << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%.=%%%+*%%%.      :%%%%%%%%%.          -%%%%%#           *%%*     :%%%=       -*%%%%%%*-                                  ";
    ScreenTheme::color_style(8);
    cout << "       :+%%%%%#*++====+++*#%%#.";
    ScreenTheme::color_style(7);
    cout << " :+%%%#=  =%%*:" << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%. :#%%%%%%.      :%%%+:::::          :#%%%%%%+          *%%*     .%%%=          .:=*%%%*                                 ";
    ScreenTheme::color_style(8);
    cout << "     -#%%%#*=---------------*";
    ScreenTheme::color_style(7);
    cout << "%%*-  =%%%#: .   " << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%.  .*%%%%%.      :%%%-              =%%%#:=%%%#.        *%%#:   .+%%%-      -+*:    *%%%.                                ";
    ScreenTheme::color_style(8);
    cout << "   :#%%%#=---------";
    ScreenTheme::color_style(2);
    cout << "%%%";
    ScreenTheme::color_style(8);
    cout << "------";
    ScreenTheme::color_style(7);
    cout << "+*%%%#- .+=:      " << endl;
    ScreenTheme::color_style(13);
    cout << "    =%%%.    +%%%%.      -%%%%%%%%%#       +%%%*   :#%%#-       .#%%%%##%%%%+      :#%%%%##%%%%+                                 ";
    ScreenTheme::color_style(8);
    cout << "  -%%%%+----------";
    ScreenTheme::color_style(2);
    cout << "*%%%+";
    ScreenTheme::color_style(8);
    cout << "----";
    ScreenTheme::color_style(7);
    cout << ":::-*%%%*          " << endl;
    ScreenTheme::color_style(13);
    cout << "    =###.     -###.      :#########*     .*###=     .*###-        -+#%%%#*=.         -+##%%#*+:                                  ";
    ScreenTheme::color_style(8);
    cout << " :%%%#=--------";
    ScreenTheme::color_style(2);
    cout << "=*#%%%%%#+-";
    ScreenTheme::color_style(7);
    cout << "::::::=%%%*         " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << ".%%%#=-------";
    ScreenTheme::color_style(2);
    cout << "=#%%%%###%%%%*";
    ScreenTheme::color_style(7);
    cout << "::::::-%%%*        " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "+%%%=--------";
    ScreenTheme::color_style(2);
    cout << "#%%%*";
    ScreenTheme::color_style(8);
    cout << "-----";
    ScreenTheme::color_style(2);
    cout << "*###+";
    ScreenTheme::color_style(7);
    cout << "::::::+%%%-       " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "#%%#---------";
    ScreenTheme::color_style(2);
    cout << "*%%%#+";
    ScreenTheme::color_style(8);
    cout << "---";
    ScreenTheme::color_style(7);
    cout << "::::::::::::-%%%*       " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "%%%*----------";
    ScreenTheme::color_style(2);
    cout << "*#%%%%%%%#*+-";
    ScreenTheme::color_style(7);
    cout << "::::::::#%%#       " << endl;
    ScreenTheme::color_style(13);
    cout << "                     =#****+-          .*#*.         -#=    :#=       **   -**.                                                  ";
    ScreenTheme::color_style(8);
    cout << "%%%#-----------";
    ScreenTheme::color_style(2);
    cout << "#%===++*%%%%=";
    ScreenTheme::color_style(7);
    cout << ":::::::#%%#       " << endl;
    ScreenTheme::color_style(13);
    cout << "                     =%:   -%)         ##=%*         -%%#:  :%+       ## .*%=                                                    ";
    ScreenTheme::color_style(8);
    cout << "*%%%=--------------";
    ScreenTheme::color_style(7);
    cout << "::::";
    ScreenTheme::color_style(2);
    cout << "*%%%*";
    ScreenTheme::color_style(7);
    cout << "::::::=%%%=       " << endl;
    ScreenTheme::color_style(13);
    cout << "                     =%#++*#%.        =%- =%-        -%*+%= .%+       #%+%%-                                                     ";
    ScreenTheme::color_style(8);
    cout << ".%%%#--------";
    ScreenTheme::color_style(2);
    cout << "=%%%%";
    ScreenTheme::color_style(7);
    cout << ":::::";
    ScreenTheme::color_style(2);
    cout << "%%%#-";
    ScreenTheme::color_style(7);
    cout << ":::::-#%%#        " << endl;
    ScreenTheme::color_style(13);
    cout << "                     =%-...-#*       :%#:.:%#.       -%= :##+%+       #%#=##:                                                    ";
    ScreenTheme::color_style(8);
    cout << " =%%%#---------";
    ScreenTheme::color_style(2);
    cout << "+#%%%%%%%#+-";
    ScreenTheme::color_style(7);
    cout << ":::::-#%%#.        " << endl;
    ScreenTheme::color_style(13);
    cout << "                     =%:   .##       *%*+++*%*       -%=   +%%+       ##   *%-                                                   ";
    ScreenTheme::color_style(8);
    cout << "  +%%%#=-------";
    ScreenTheme::color_style(7);
    cout << "::";
    ScreenTheme::color_style(2);
    cout << "-*%%%*-";
    ScreenTheme::color_style(7);
    cout << "::::::-+%%%#.         " << endl;
    ScreenTheme::color_style(13);
    cout << "                     =####**=.      -#=     =#-      -#-    -*=       **    +#-                                                  ";
    ScreenTheme::color_style(8);
    cout << "   -#%%%*=----";
    ScreenTheme::color_style(7);
    cout << "::::";
    ScreenTheme::color_style(2);
    cout << "-%%%-";
    ScreenTheme::color_style(7);
    cout << ":::::=*%%%%=           " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "     =%%%%*+*";
    ScreenTheme::color_style(7);
    cout << ":::::::";
    ScreenTheme::color_style(2);
    cout << "%";
    ScreenTheme::color_style(7);
    cout << ":::::*%%%%#=.            " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(8);
    cout << "       =%%#*";
    ScreenTheme::color_style(7);
    cout << "%%%%%%%%%%%%%%%%#+-               " << endl;
    cout << "                                                                                                                                 ";
    ScreenTheme::color_style(7);
    cout << "             .-=+*#####*+=:.                  " << endl;

}

int Screens::login_as_menu(){
    string menu = "\n###################\n"
                  "# 1. Client       #\n"
                  "# 2. Admin        #\n"
                  "# 3. Employee     #\n"
                  "# 4. Exit         #\n"
                  "###################\n";
    return ScreenTheme::choose_them(menu,4,75,31);
}
