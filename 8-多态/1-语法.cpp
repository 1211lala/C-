/*
    静态多态: 函数重载,运算符重载
    动态多态: 父类中有一个虚函数,在子类中重写他
                优点: 宜于扩展


            虚函数: virtual int get_result()
            纯虚函数:  virtual int get_result() = 0;
 */

#include <iostream>
#include <string>
using namespace std;

class BaseCalc
{
public:
    virtual int get_result() = 0;
    // {
    //     return 0;
    // }
    virtual void show_info()
    {
        cout << "这是计算器基类" << endl;
    }
    int m_number1;
    int m_number2;
};

class MulCalc : public BaseCalc
{
public:
    int get_result()
    {
        return this->m_number1 * this->m_number2;
    }
    void show_info()
    {
        cout << "这是计算器乘法" << endl;
    }
};
class AddCalc : public BaseCalc
{
public:
    int get_result()
    {
        return this->m_number1 + this->m_number2;
    }
    void show_info()
    {
        cout << "这是计算器加法" << endl;
    }
};
int main(void)
{
    MulCalc *mul = new MulCalc;
    mul->m_number1 = 100;
    mul->m_number2 = 200;
    mul->show_info();
    cout << mul->get_result() << endl;
    delete mul;

    BaseCalc *add = new AddCalc;
    add->m_number1 = 100;
    add->m_number2 = 200;
    add->show_info();
    cout << add->get_result() << endl;

    return 0;
}