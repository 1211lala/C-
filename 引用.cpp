/**
 * 引用---给一个数据起个别名,共用一片内存地址, 本质的实现方法为指针常量 int &a = b; == int *const a = &b;

    int b = 10;
    int &a = b;

    cout << "&a" << &a << endl;
    cout << "&b" << &b << endl;


    int (*fun)(int &arg1, int &arg2)
    int (*fun)(const int &arg1, const int &arg2)

    注意:   引用必须初始化
            引用在初始化后就不可以修改
 */
#include <iostream>
using namespace std;

int main(void)
{

    return 0;
}