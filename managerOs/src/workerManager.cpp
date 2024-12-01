#include "datafile.h"

void workerManager::show_menu(void)
{
    cout << "\n**********************************************************" << endl;
    cout << "*******************  职 工 管 理 系 统 *******************" << endl;
    cout << "*******************  <0> 退出管理系统  *******************" << endl;
    cout << "*******************  <1> 增加职工信息  *******************" << endl;
    cout << "*******************  <2> 显示职工信息  *******************" << endl;
    cout << "*******************  <3> 删除职工信息  *******************" << endl;
    cout << "*******************  <4> 修改职工信息  *******************" << endl;
    cout << "*******************  <5> 查找职工信息  *******************" << endl;
    cout << "*******************  <6> 按照编号排序  *******************" << endl;
    cout << "*******************  <7> 清空职工信息  *******************" << endl;
}
void workerManager::exit_system(void)
{
    cout << "即将退出系统" << endl;
    exit(0);
}

workerManager::workerManager()
{
    this->empNum = 0;
    this->empArray = NULL;
    this->fileIsExist = true;
    this->fileIsEmpty = false;

    ifstream ifs;
    ifs.open(MANAGER_OS_FILE, ios::in);
    if (!ifs.is_open()) // 文件不存在
    {
        cout << "文件不存在" << endl;

        this->fileIsExist = false;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    ifs.close();

    ifs.open(MANAGER_OS_FILE, ios::in);
    char ch;
    ifs >> ch;
    if (ifs.eof()) // 文件为空
    {
        cout << "文件为空" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    ifs.close();
    this->empNum = this->get_file_emp_num();
    cout << "当前职工人数" << this->get_file_emp_num() << endl;
}
workerManager::~workerManager()
{
    if (this->empArray != NULL)
    {
        delete[] this->empArray;
        this->empArray = NULL;
    }
}

void workerManager::add_emp()
{
    cout << "请输入添加职工的数量: ";
    int add_num;
    cin >> add_num;
    if (add_num > 0)
    {
        int newSize = this->empNum + add_num; // 记录总人数
        /* newNmpArray** 的成员为 newNmpArray* 指向 boss employee manager */
        baseWorker **newNmpArray = new baseWorker *[newSize]; // 开辟一块新的可以容乃新添加的人数的指针内存
        if (this->empArray != NULL)
        {
            for (int i = 0; i < this->empNum; i++)
            {
                newNmpArray[i] = this->empArray[i];
            }
        }
        // 添加员工
        for (int i = 0; i < add_num; i++)
        {
            int add_id = 0;
            string add_name = "";
            int add_did = 0;

            cout << "请输入第" << i + 1 << "位新职工编号: ";
            cin >> add_id;
            cout << "请输入第" << i + 1 << "位新职工姓名: ";
            cin >> add_name;
            cout << "请输入第" << i + 1 << "位新职工部门 1:普通职工 2:集团经理  3:集团老板: ";
            cin >> add_did;

            baseWorker *add_worker;
            switch (add_did)
            {
            case 1:
                add_worker = new employee(add_id, add_name, add_did);
                break;
            case 2:
                add_worker = new manager(add_id, add_name, add_did);
                break;
            case 3:
                add_worker = new boss(add_id, add_name, add_did);
                break;
            default:
                break;
            }
            newNmpArray[this->empNum + i] = add_worker;
        }
        delete[] this->empArray;      // 释放原有数据
        this->empArray = newNmpArray; // 指向新数据
        this->empNum = newSize;
        this->save_file();
        cout << "成功添加" << add_num << "新职工" << endl;
    }
    else
    {
        cout << "添加人数输入错误" << endl;
    }
}

void workerManager::save_file()
{
    fstream fs;
    fs.open(MANAGER_OS_FILE, ios::out);
    char tempbuf[500];
    for (int i = 0; i < this->empNum; i++)
    {
        sprintf(tempbuf, "%d %s %d\n", this->empArray[i]->id, this->empArray[i]->name.c_str(), this->empArray[i]->dept_id);
        fs.write(tempbuf, strlen(tempbuf));
    }
    fs.close();
    this->fileIsEmpty = false;
    this->fileIsExist = true;
}

int workerManager::get_file_emp_num(void)
{
    ifstream ifs;
    ifs.open(MANAGER_OS_FILE, ios::in);
    int id;
    string name;
    int did;
    int number = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        number += 1;
    }
    return number;
}

void workerManager::load_file(void)
{
    int id;
    string name;
    int did;

    ifstream ifs;
    this->empArray = new baseWorker *[this->empNum]; // 分配内存
    ifs.open(MANAGER_OS_FILE, ios::in);
    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        baseWorker *worker;
        switch (did)
        {
        case 1:
            worker = new employee(id, name, did);
            break;
        case 2:
            worker = new manager(id, name, did);
            break;
        case 3:
            worker = new boss(id, name, did);
            break;
        }
        this->empArray[num] = worker;
        num += 1;
    }
    ifs.close();
}

void workerManager::show_info()
{
    if (!this->fileIsExist)
    {
        cout << "文件不存在, 请输入员工信息后再尝试" << endl;
        return;
    }
    if (this->fileIsEmpty)
    {
        cout << "文件为空, 请输入员工信息后再尝试" << endl;
        return;
    }
    for (int i = 0; i < this->empNum; i++)
    {
        this->empArray[i]->show_info();
    }
}

int workerManager::emp_is_exit(int id)
{
    for (int i = 0; i < this->empNum; i++)
    {
        if (this->empArray[i]->id == id)
        {
            return i;
        }
    }
    return -1;
}

bool workerManager::delete_emp()
{
    cout << "请输入想要删除的职工ID: ";
    int delete_id;
    int index_id;
    cin >> delete_id;
    index_id = this->emp_is_exit(delete_id);
    if (index_id >= 0)
    {
        for (int i = index_id; i < this->empNum - 1; i++)
        {
            this->empArray[i] = this->empArray[i + 1];
        }
        this->empNum -= 1;
        this->save_file();
        cout << "职工ID: " << delete_id << "<<删除成功" << endl;
        return true;
    }
    cout << "ID:" << delete_id << "不存在" << endl;
    return false;
}

bool workerManager::change_emp()
{
    cout << "请输入想要修改的职工ID: ";
    int change_id;
    cin >> change_id;
    int index_id = this->emp_is_exit(change_id);
    if (index_id >= 0)
    {
        this->empArray[index_id]->show_info();
        int add_id = 0;
        string add_name = "";
        int add_did = 0;

        cout << "请输入职工新编号: ";
        cin >> add_id;
        cout << "请输入职工新姓名: ";
        cin >> add_name;
        cout << "请输入职工新岗位: 1:普通职工 2:集团经理  3:集团老板: ";
        cin >> add_did;
        baseWorker *add_worker;
        switch (add_did)
        {
        case 1:
            add_worker = new employee(add_id, add_name, add_did);
            break;
        case 2:
            add_worker = new manager(add_id, add_name, add_did);
            break;
        case 3:
            add_worker = new boss(add_id, add_name, add_did);
            break;
        default:
            break;
        }
        delete this->empArray[index_id];       // 释放之前的内存
        this->empArray[index_id] = add_worker; // 将新的信息添加
        cout << "编号: " << change_id << "修改完成:" << endl;
        this->save_file();
        return true;
    }
    cout << "编号为: " << change_id << "不存在" << endl;
    return false;
}

bool workerManager::find_emp()
{
    cout << "查找职工方式   1:编号  2:姓名  ";
    int choice;
    cin >> choice;
    if (1 == choice)
    {
        int find_id;
        cout << "请输入需要查找的职工编号: ";
        cin >> find_id;
        int array_index = this->emp_is_exit(find_id);
        if (array_index >= 0)
        {
            this->empArray[array_index]->show_info();
            return true;
        }
        else
        {
            cout << "职工不存在" << endl;
        }
    }
    else if (2 == choice)
    {
        string find_name;
        int array_index = -1;
        cout << "请输入需要查找的职工姓名: ";
        cin >> find_name;
        for (int i = 0; i < this->empNum; i++)
        {
            if (this->empArray[i]->name == find_name)
            {
                array_index = i;
            }
        }
        if (array_index >= 0)
        {
            this->empArray[array_index]->show_info();
            return true;
        }
        else
        {
            cout << "职工不存在" << endl;
        }
    }
    else
    {
        cout << "输入错误的查找方式: " << choice << endl;
    }
    return false;
}

bool workerManager::sort_emp()
{
    // for()
}