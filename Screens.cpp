#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Screens.h"
using namespace std;

void Screens::loading_screen() {
    cout << "\n\n\n";
    cout << "\t\t\t\t\t\t           G############################BBBBBBBB############################G           " << endl;
    cout << "\t\t\t\t\t\t         .?B?!!!!!!!!!!!!!!!!!!!!!!!!!!?J5GBBG5J?!!!!!!!!!!!!!!!!!!!!!!!!!!?B7.         " << endl;
    cout << "\t\t\t\t\t\t       .?#@.                       .!YB###GGGG###BY!.                        @#?.       " << endl;
    cout << "\t\t\t\t\t\t     :J&@G!                      ~P&@BJ          JG@&P~                      !G@&J:     " << endl;
    cout << "\t\t\t\t\t\t   :Y&@P~                      ^G@&J:     .$$.     ^J&@P^                      ~P@&Y^   " << endl;
    cout << "\t\t\t\t\t\t ^5&@G!:::::::::              ?@@Y.       /$$\\       .Y@@?              :::::::::!G@&5^ " << endl;
    cout << "\t\t\t\t\t\t~#@@&#########&&7            ?@@7     $$$$$$$$$$$$$    7@@?            7&&#########&&@#~" << endl;
    cout << "\t\t\t\t\t\t              &@J           ^&@J     $$$  |$$|          J@&^           J@&              " << endl;
    cout << "\t\t\t\t\t\t              &@J           J@#:     $$$  |$$|          :#@J           J@&              " << endl;
    cout << "\t\t\t\t\t\t!@@&&&&&&&&&&&&&7           5@B.      $$$$$$$$$$$       .B@5           7&&&&&&&&&&&&&@@!" << endl;
    cout << "\t\t\t\t\t\t7@&                         ?@&:          |$$| $$$      :&@?                         &@7" << endl;
    cout << "\t\t\t\t\t\t7@&                         ?@@5          |$$| $$$      Y@@                          &@7" << endl;
    cout << "\t\t\t\t\t\t~@@@##################&@@#####@@J    $$$$$$$$$$$$$     J@@#####@@&##################@@@~" << endl;
    cout << "\t\t\t\t\t\t !&@Y                !&@Y     !#@P^       \\$$/       ^P@#!     Y@&!                Y@&!" << endl;
    cout << "\t\t\t\t\t\t  !&@5              ?&@Y       :Y@@P!.    .$$.    .!P@@Y:       Y@&?              5@&!  " << endl;
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
    bank_name();
    cout << "\n\n\n\t\t\t\t\t\t\t\tLoading  ";
    char x = (char)219;
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
    cout << "\t\t\t                                                                              ****+.         *        .*-   +=     :*  .*=                " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              #     )       %=#       .%%+  **     :%.=#-                 " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              # ++*<       #+ +#      .%-=#-**     :%##*                  " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              #     )     +#+++#+     .%:  #%*     :%: +#.                " << endl;
    Sleep(50);
    cout << "\t\t\t                                                                              +++++`     .+.   .+.     +.   ==     .+   -+                " << endl;
    Sleep(400);
    system("cls");
}