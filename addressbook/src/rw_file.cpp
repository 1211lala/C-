#include "datafile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// 从文件中解析每一行的联系人信息
bool parseLine(const string &line, PERSON &person)
{
    stringstream ss(line);
    string temp;

    // 跳过序号
    if (!getline(ss, temp, '>'))
        return false;

    // 解析姓名
    if (!(ss >> person.name))
        return false;

    // 解析电话号码
    if (!(ss >> person.number))
        return false;

    // 解析地址
    if (!(ss >> person.address))
        return false;

    // 解析年龄
    if (!(ss >> person.age))
        return false;

    // 解析性别
    string sex_str;
    if (!(ss >> sex_str))
        return false;
    person.sex = (sex_str == "男") ? 1 : 0;

    return true;
}

/*********************************************************************************************
 *
 */
int load_info_from_file(struct ADDRESS_BOOK &ab, const string path)
{
    ifstream infile(path);
    if (!infile)
    {
        cerr << "无法打开文件: " << path << endl;
        return -1;
    }

    string line;
    int err_num_line = 0;
    while (getline(infile, line))
    {
        if (parseLine(line, ab.person[ab.num_person]))
        {
            ab.num_person += 1;
        }
        else
        {
            err_num_line -= 1;
        }
    }
    infile.close();
    return err_num_line;
}

/*********************************************************************************************
 *
 */
int write_info_to_file(struct ADDRESS_BOOK &ab, const string path)
{
    char temp[200];

    FILE *f = fopen(path.c_str(), "w");
    if (f == NULL)
    {
        cout << path << "open fail" << endl;
        return -1;
    }
    for (int i = 0; i < ab.num_person; i++)
    {
        sprintf(temp, "<%03d>\t%s\t%s\t%s\t%d\t%s\n",
                i, ab.person[i].name.c_str(), ab.person[i].number.c_str(), ab.person[i].address.c_str(), ab.person[i].age, ab.person[i].sex ? "男" : "女");

        fwrite(temp, sizeof(char), strlen(temp), f);
    }
    fclose(f);
    return 0;
}