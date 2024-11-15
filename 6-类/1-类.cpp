/*
    封装、继承、多态
    私有变量和保护标量在类外不可访问

*/

#include <iostream>
#include <unistd.h>
using namespace std;

#define PI 3.1415926

class CIRCLE
{
private:
    /* data */
public:
    int r;
    double get_length();

    CIRCLE();
    CIRCLE(const string &arg);
    CIRCLE(const CIRCLE &arg);
    ~CIRCLE();
};
double CIRCLE::get_length()
{
    return 2 * r * PI;
}
CIRCLE::CIRCLE()
{
    cout << "CIRCLE 的无参构造被调用" << endl;
}
CIRCLE::CIRCLE(const string &arg)
{
    cout << "CIRCLE 的有参构造被调用:" << arg << endl;
}
CIRCLE::CIRCLE(const CIRCLE &arg)
{
    cout << "CIRCLE 的拷贝构造被调用:" << endl;
}
CIRCLE::~CIRCLE()
{
    cout << "CIRCLE 的析构函数被调用" << endl;
}

int main(void)
{
    CIRCLE circle1;             /* 无参构造 */
    CIRCLE circle2("有参构造"); /* 有参构造 */
    CIRCLE circle3(circle2);    /* 拷贝构造 */
    CIRCLE circle4();           /* 这个是一个返回 CIRCLE 对象的函数声明 */

    CIRCLE circle5 = CIRCLE("显示发");
    CIRCLE circle6 = CIRCLE(circle2);



    // CIRCLE circle7 = "隐式转换法";
    circle1.r = 10;
    cout << "zc=" << circle1.get_length() << endl;

    return 0;
}