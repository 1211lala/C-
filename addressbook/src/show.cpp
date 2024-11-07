#include "datafile.h"

void show_list(struct ADDRESS_BOOK *ad)
{
    for (int i = 0; i < ad->num_person; i++)
    {
        printf("<%d>\t%s\t%s\t%s\t%d\t%s\n",
               i, ad->person[i].name.c_str(),
               ad->person[i].number.c_str(),
               ad->person[i].address.c_str(),
               ad->person[i].age,
               ad->person[i].sex ? "男" : "女");
    }
}

void show_menu(void)
{
    cout << "\t\t****************************" << endl;
    cout << "\t\t****** 0、退出通讯录 ******" << endl;
    cout << "\t\t****** 1、添加联系人 ******" << endl;
    cout << "\t\t****** 2、显示联系人 ******" << endl;
    cout << "\t\t****** 3、删除联系人 ******" << endl;
    cout << "\t\t****** 4、查找联系人 ******" << endl;
    cout << "\t\t****** 5、修改联系人 ******" << endl;
    cout << "\t\t****** 6、清空联系人 ******" << endl;
    cout << "\t\t****************************" << endl;
}