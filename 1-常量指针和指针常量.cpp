#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;


int main(void)
{
    // /* 常量指针 指针指向的值不能通过 *p1 = 20 直接修改,可以通过 p1 = &b 修改指针指向的值 */
    // int a = 10;
    // int b = 10;
    // int c = 50;
    // const int *p1 = &a;
    // // *p1 = 100; // 会报错
    // p1 = &b;
    // p1 = &c;
    // cout << *p1 << endl;

    // /* 指针常量 指针指向的值可以通过 *p1 = 20 直接修改,不可以通过 p1 = &b 修改指针指向*/
    // int a = 10;
    // int b = 10;
    // int c = 50;
    // int *const p1 = &a;
    // // p1 = &c; // 会报错
    // *p1 = 100;
    // cout << *p1 << endl;
    // return 0;
    // /* 常量指针常量 指针指向的值不可以通过 *p1 = 20 直接修改,不可以通过 p1 = &b 修改指针指向*/
    // int a = 10;
    // int b = 10;
    // int c = 50;
    // const int *const p1 = &a;
    // *p1 = 100; // 会报错
    // p1 = &b;   // 会报错
    // cout << *p1 << endl;
    // return 0;
}