#include "datafile.h"
struct ADDRESS_BOOK address_book = {};

int main(void)
{

    int cmd = 0;
    load_info_from_file(address_book, "../address_book.txt");
    while (1)
    {
        show_menu();
        cin >> cmd;

        switch (cmd)
        {
        case AB_EXIT:
            write_info_to_file(address_book, "../address_book.txt");
            cout << "欢迎下次使用" << endl;
            return 0;
            break;
        case AB_ADD:
            add_person(&address_book);
            break;
        case AB_SHOW:
            cout << "查看记录\n"
                 << endl;
            show_list(&address_book);
            break;
        case AB_RM:

            break;
        case AB_FIND:

            break;
        case AB_CLEAR:

            break;
        default:
            break;
        }
    }

    return 0;
}
