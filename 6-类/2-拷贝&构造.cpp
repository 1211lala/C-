/*
    拷贝构造 >> 有参构造 >> 无参构造

    无参构造 空实现
    有参构造 空实现
    拷贝构造 编译器会把 原对象的属性拷贝到当前对象
 */
/*
    浅拷贝: 简单的赋值拷贝操作
    深拷贝: 在堆区申请内存,进行拷贝操作
 */

#include <iostream>

using namespace std;

class Person
{
private:
public:
    int age;
    Person();
    Person(int age);
    Person(const Person &p);
    ~Person();
};
Person::Person()
{
    cout << "无参构造" << endl;
}
Person::Person(int age)
{
    this->age = age;
    cout << "有参构造" << endl;
}

Person::Person(const Person &p)
{
    this->age = p.age;
    cout << "拷贝构造" << endl;
}
Person::~Person()
{
    cout << "析构函数" << endl;
}

int main(void)
{
    Person p1;
    p1.age = 20;

    Person p2 = Person(p1);
    cout << "p1.age= " << p1.age << endl;
    cout << "p2.age= " << p2.age << endl;
    return 0;
}