/**
 * new 操作符用于动态分配内存，它在堆（heap）上为指定类型分配足够的内存，并返回指向该内存的指针, 需要使用 delete 释放
 *
 * int *p = new(int)            delete p
 * int *p = new int(10)         delete p
 * int *p = new int[5]          delete[] p
 */

#include <iostream>
using namespace std;

int main(void)
{
    int *a = new int[10];
    for (int i = 0; i < 10; i++)
    {
        *(a + i) = i;
    }
    cout << *(a + 1) << endl;

    delete[] a;
    return 0;
}