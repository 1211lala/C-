#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

fstream fs;
class Person
{
private:
    /* data */
public:
    int age;
    char name[20];
};

int main(void)
{
    Person p1;
    p1.age = 24;
    memcpy(p1.name, "jack.jio", strlen("jack.jio"));
    fs.open("./text", ios::binary | ios::out);
    fs.write((const char *)&p1, sizeof(Person));
    fs.close();

    Person *p2 = (Person *)malloc(sizeof(Person));
    fs.open("./text", ios::binary | ios::in);
    fs.read((char *)p2, sizeof(Person));
    fs.close();

    cout << "年龄" << p2->age << "\t名字" << p2->name << endl;
    free(p2);
}