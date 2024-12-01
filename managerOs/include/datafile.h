#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MANAGER_OS_FILE "/home/liuao/C-/managerOs/datafile.txt"

class baseWorker;
/***************************************************************************** */
class workerManager
{
private:
    /* data */
public:
    int empNum; // 职工总人数
    bool fileIsExist;
    bool fileIsEmpty;
    baseWorker **empArray;
    void show_menu(void);
    void exit_system(void);
    void add_emp();
    void save_file();
    int get_file_emp_num();
    void load_file();
    void show_info();
    int emp_is_exit(int id);
    bool delete_emp();
    bool change_emp();
    bool find_emp();
    bool sort_emp();
    ~workerManager();
    workerManager();
};

/***************************************************************************** */
class baseWorker
{
private:
    /* data */
public:
    virtual void show_info(void) = 0;
    virtual string get_dept_name(void) = 0;
    int id;
    int dept_id;
    string name;
};

/*****************************************************************************/
class employee : public baseWorker
{
private:
    /* data */
public:
    void show_info(void);
    string get_dept_name(void);
    employee(int id, string name, int did);
    ~employee();
};

class manager : public baseWorker
{
public:
    void show_info(void);
    string get_dept_name(void);
    manager(int id, string name, int did);
    ~manager();
};

class boss : public baseWorker
{
public:
    void show_info(void);
    string get_dept_name(void);
    boss(int id, string name, int did);
    ~boss();
};