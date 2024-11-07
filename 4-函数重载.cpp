/*
    函数只有在同一个作用域下、函数名称相同、函数参数个数不同、顺序不同 才能重载


    注

*/

#include <iostream>

using namespace std;

void fun(int a)
{
    cout << "a=" << a << endl;
}
void fun(int a, int b)
{
    cout << "a=" << a << "\tb=" << b << endl;
}

void fun2(int &a)
{
    cout << "void fun(int &a)" << endl;
}
void fun2(const int &a)
{
    cout << "void fun2(const int &a)" << endl;
}

int main(void)
{
    fun(10);
    fun(10, 20);

    const int a = 10;
    fun2(10);
    fun2(a);

    int b = 100;
    fun2(b);
}