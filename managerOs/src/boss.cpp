#include "datafile.h"

void boss::show_info(void)
{
    cout << "职工编号:" << this->id << "\t"
         << "职工名字:" << this->name << "\t"
         << "职工岗位:" << this->get_dept_name() << "\t"
         << "岗位职责:" << "制定任务,管理事务" << endl;
}
string boss::get_dept_name(void)
{
    return string("集团老板");
}
boss::boss(int id, string name, int did)
{
    this->id = id;
    this->name = name;
    this->dept_id = did;
}

boss::~boss()
{
}