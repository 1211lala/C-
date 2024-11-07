#include "datafile.h"

void add_person(struct ADDRESS_BOOK *ad)
{
    if (ad->num_person >= MAX_PERSON_NUM)
    {
        cout << "通讯录人数达到最大值" << endl;
        return;
    }
    cout << "请输入添加者姓名:";
    cin >> ad->person[ad->num_person].name;
    usleep(100000);
    cout << "请输入添加者手机号码:";
    cin >> ad->person[ad->num_person].number;
    usleep(100000);
    cout << "请输入添加者居住地址:";
    cin >> ad->person[ad->num_person].address;
    usleep(100000);
    cout << "请输入添加者年龄:";
    cin >> ad->person[ad->num_person].age;
    usleep(100000);
    cout << "请输入添加者性别:<1:男 0:女>";
    cin.clear();
    cin >> ad->person[ad->num_person].sex;
    while (ad->person[ad->num_person].sex != 1 && ad->person[ad->num_person].sex != 0)
    {
        cout << "输入错误,请重新输入:<1:男 0:女>";
        cin.clear();
        cin >> ad->person[ad->num_person].sex;
    }
    usleep(100000);

    int istrue = 0;
    cout << "确认添加:<1:Yes 0:NO>";
    cin.clear();
    cin >> istrue; // 得到的是ascll 码值
    usleep(100000);
    while (istrue != 1 && istrue != 0)
    {
        cout << "输入错误,请重新输入:<1:Yes 0:NO>";
        cin.clear();
        cin >> istrue;
    }
    if (istrue == 0)
    {
        memset(&ad->person[ad->num_person], 0, sizeof(struct PERSON));
        return;
    }
    ad->num_person += 1;
    cin.clear();
}