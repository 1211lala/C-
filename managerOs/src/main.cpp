#include "datafile.h"

workerManager wm;

int main(void)
{
    wm.load_file();
    int user_choice = 0;
    while (true)
    {
        wm.show_menu();
        cin >> user_choice;

        switch (user_choice)
        {
        case 0:
            wm.exit_system();
            break;
        case 1:
            wm.add_emp();
            break;
        case 2:
            wm.show_info();
            break;
        case 3:
            wm.delete_emp();
            break;
        case 4:
            wm.change_emp();
            break;
        case 5:
            wm.find_emp();
            break;
        case 6:
            wm.sort_emp();
            break;
        case 7:
            wm.clear_os_info();
            break;
        default:
            system("clear");
            break;
        }
    }
    return 0;
}
