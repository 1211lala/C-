/*
    int (*fun)(int a=10, int b= 20, int c= 30)


    注:
        在一个参数的位置有了默认参数，那么在这个位置后的参数都必须要有默认参数
        函数的声明有默认参数，那么函数的实现就不能有默认参数，反之亦然
*/

#include <iostream>

using namespace std;

int fun(int a, int b = 20, int c = 20)
{
    return a + b + c;
}


// 声明
int fun2(int a = 888, int b = 45);
// 实现
int fun2(int a, int b)
{
    return a + b;
}
int main(void)
{
    cout << fun(60, 3489) << endl;
    cout << fun2() << endl;
    return 0;
}