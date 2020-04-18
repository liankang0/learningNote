// coding:utf-8

// **********************************************************
// * Author        : liankang
// * Email         : 349915905@qq.com
// * Create time   : 2019-07-30 21:56
// * Filename      : Singleton1.cc
// * Description   : 
// **********************************************************
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

//单例对象自动释放
//方法一：静态成员函数 + atexit

class Singleton
{
public:
    static Singleton* getInstance()
    {
        //非线程安全
        //加锁
        if(NULL == _pInstance)
        {
            ::atexit(destroy);
            _pInstance = new Singleton();
        }
        return _pInstance;
        
    }
    
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

private:
    //非静态数据成员就是单例对象的一部分
    static Singleton* _pInstance;

};
//Singleton * Singleton::_pInstance = nullptr;//懒(懒加载)汉模式

//在进入main函数之前就创建单例对象
Singleton * Singleton::_pInstance = getInstance();//饿汉模式


int main(int argc, char** argv)
{
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    Singleton* p3 = Singleton::getInstance();
    cout << "p1 = " << p1 << endl
            << "p2 = " << p2 << endl
            << "p3 = " << p3 << endl;
    return 0;
}

