#include "datafile.h"

void employee::show_info(void)
{
    cout << "职工编号:" << this->id << "\t"
         << "职工名字:" << this->name << "\t"
         << "职工岗位:" << this->get_dept_name() << "\t"
         << "岗位职责:" << "完成经理的任务" << endl;
}
string employee::get_dept_name(void)
{
    return string("普通员工");
}
employee::employee(int id, string name, int did)
{
    this->id = id;
    this->name = name;
    this->dept_id = did;
}

employee::~employee()
{
}