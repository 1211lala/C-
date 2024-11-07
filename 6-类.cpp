/*
    封装、继承、多态

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
    ~CIRCLE();
};
double CIRCLE::get_length()
{
    return 2 * r * PI;
}
CIRCLE::CIRCLE()
{
    cout << "CIRCLE::CIRCLE()" << endl;
}
CIRCLE::~CIRCLE()
{
    cout << "CIRCLE::~CIRCLE()" << endl;
}

CIRCLE circle1;
int main(void)
{
    circle1.r = 10;
    cout << "zc=" << circle1.get_length() << endl;
    while (1)
    {
        sleep(1);
    }
    return 0;
}