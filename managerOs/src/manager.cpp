#include <datafile.h>

void manager::show_info(void)
{
    cout << "职工编号:" << this->id << "\t"
         << "职工名字:" << this->name << "\t"
         << "职工岗位:" << this->get_dept_name() << "\t"
         << "岗位职责:" << "完成老板的任务,下发任务给职工" << endl;
}
string manager::get_dept_name(void)
{
    return string("集团经理");
}

manager::manager(int id, string name, int did)
{
    this->id = id;
    this->name = name;
    this->dept_id = did;
}

manager::~manager()
{
}