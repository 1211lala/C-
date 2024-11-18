/*
    虚析构函数为了解决 父类指针在析构时不会走子类的析构函数
        Animal *cat = new Cat("Tom");
        cat->speak();
        delete cat;

    解决方法: 将父类的析构函数改为虚析构或纯虚析构
        与虚函数不同: 析构函数的纯虚函数也需要自己实现, 编译器不会帮我添加
 */

#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    /* data */
public:
    virtual void speak(void) = 0;
    Animal(/* args */);
    virtual ~Animal();
    // virtual ~Animal() = 0;
};

Animal::Animal(/* args */)
{
}

Animal::~Animal()
{
}

class Cat : public Animal
{
private:
    /* data */
public:
    void speak(void)
    {
        cout << *this->name << "小猫在说话" << endl;
    }
    string *name;
    Cat(string name);
    ~Cat();
};

Cat::Cat(string name)
{
    /* 将数据放在堆区 */
    this->name = new string(name);
}

Cat::~Cat()
{
    cout << *this->name << "析构" << endl;
    if (this->name != NULL)
    {
        delete this->name;
        this->name = NULL;
    }
}

int main(void)
{
    Animal *cat = new Cat("Tom");
    cat->speak();
    delete cat;
}