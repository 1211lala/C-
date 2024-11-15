/*
    class B
    {
        ....
    }

    class A: <public/private/protected>B
    {
    }
    共有继承
    保护继承
    私有继承
    继承会把父类的所有数据继承过来, 有的数据有权限限制看不了,但是还是占用实际内存的





    如果父类与子类中有相同名称的属性或函数, 子类会隐藏父类的所有属性和函数包括重载
        a.name          是子类中的
        a.B::name       是父类中的

        a.name()        是子类中的函数
        a.B::name()     是父类中的

    对于静态属性和方法,如果父类与子类中有相同名称的属性或函数
    在类外初始化  int A::age = 100;  子类的初始化
                 a.age = 100;       子类中的访问和修改

                int B::age = 100;   父类的初始化
                a.B::age = 100;     父类的初始化在子类中的访问和修改
                A::B::age = 100;    父类的初始化在子类中的访问和修改





    继承多个父对象
        class A : <public/private/protected>B, <public/private/protected>C, <public/private/protected>D





    菱形继承: 会继承两份相同是数据 如下 会继承相同是数据A
        虚继承

        class A
        |     |
        |     |
    class B class C
        |     |
        |     |
        class D

    class B: virtual public A
    class C: virtual public A

    class D: public B, public C
 */

#include <iostream>
#include <stdio.h>

using namespace std;

class Proson
{
private:
    /* data */
public:
    Proson(/* args */);
    ~Proson();
};

Proson::Proson(/* args */)
{
    printf("Proson的构造函数\n");
}

Proson::~Proson()
{
    printf("Proson的析构函数\n");
}

class Student : public Proson
{
private:
    /* data */
public:
    Student(/* args */);
    ~Student();
};

Student::Student(/* args */)
{
    printf("Student的构造函数\n");
}

Student::~Student()
{
    printf("Student的析构函数\n");
}

int main(int argc, char **argv)
{
    Student s;
    return 0;
}