/*

 */

#include <iostream>
#include <string>
using namespace std;

class BaseDrinking
{
public:
    virtual void select_water(void) = 0;
    virtual void select_materials(void) = 0;
    virtual void make_it(void) = 0;

    void do_drink(void)
    {
        select_water();
        select_materials();
        make_it();
    }
};

class Tea : public BaseDrinking
{
private:
    /* data */
public:
    virtual void select_water(void)
    {
        cout << "选择山泉水作为茶的水" << endl;
    }
    virtual void select_materials(void)
    {
        cout << "制作茶" << endl;
    }
    virtual void make_it(void)
    {
        cout << "茶制作完成" << endl;
    }
};

class Coffee : public BaseDrinking
{
private:
    /* data */
public:
    virtual void select_water(void)
    {
        cout << "选择自来水的水" << endl;
    }
    virtual void select_materials(void)
    {
        cout << "制作咖啡" << endl;
    }
    virtual void make_it(void)
    {
        cout << "咖啡制作完成" << endl;
    }
};
int main(void)
{

    Tea *tea = new Tea;
    tea->do_drink();
    delete tea;

    Coffee coffee;
    coffee.do_drink();
    return 0;
}