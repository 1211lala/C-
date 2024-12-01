#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

void test_01(void)
{
    vector<int> v;
    for (int i = 0; i < 1000; i++)
    {
        v.push_back(rand() % 100);
    }
    vector<int>::iterator vbegin = v.begin();
    vector<int>::iterator vend = v.end();
    for (int i = 0; vbegin != vend; i++, vbegin++)
    {
        printf("v[%d]: %d\n", i, (*vbegin));
    }
}
void test_02(void)
{
    vector<string> v;
    string str = "";
    for (int i = 0; i < 10; i++)
    {
        str += "1";
        v.push_back(str);
    }
    vector<string>::iterator vbegin = v.begin();
    vector<string>::iterator vend = v.end();
    for (int i = 0; vbegin != vend; i++, vbegin++)
    {
        printf("v[%d]: %s\n", i, (*vbegin).c_str());
    }
}

void test_03(void)
{
    class Person
    {
    private:
        /* data */
    public:
        int age;
        string name;
    };

    vector<Person> v;
    Person p;
    for (int i = 0; i < 10; i++)
    {
        p.age = i * 10;
        p.name += "i";
        v.push_back(p);
    }
    vector<Person>::iterator vbegin = v.begin();
    vector<Person>::iterator vend = v.end();
    for (int i = 0; vbegin != vend; i++, vbegin++)
    {
        printf("v[%d]: age: %d  name:%s\n", i, (*vbegin).age, (*vbegin).name.c_str());
    }
}

void test_04(void)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i * 1);
        v2.push_back(i * 2);
        v3.push_back(i * 3);
    }
    vector<vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    printf("v1 size: %ld v2 size: %ld v3 size: %ld vv size: %ld\n", v1.size(), v2.size(), v3.size(), vv.size());

    vector<vector<int>>::iterator vvbegin = vv.begin();
    vector<vector<int>>::iterator vvend = vv.end();
    for (int i = 0; vvbegin != vvend; i++, vvbegin++)
    {
        vector<int>::iterator v_it_begin = (*vvbegin).begin();
        vector<int>::iterator v_it_end = (*vvbegin).end();
        for (int j = 0; v_it_begin != v_it_end; j++, v_it_begin++)
        {
            printf("v[%d][%d]: %d\n", i, j, (*v_it_begin));
        }
    }
    v1.clear();
    v2.clear();
    v3.clear();
    vv.clear();
    printf("v1 size: %ld v2 size: %ld v3 size: %ld vv size: %ld\n", v1.size(), v2.size(), v3.size(), vv.size());
}
int main(void)
{
    test_01();
    test_02();
    test_03();
    test_04();
}