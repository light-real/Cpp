/*
std::weak_ptr 是一个不控制资源生命周期的智能指针，是对对象的一种弱引用，
只是提供了对其管理的资源的一个访问手段，引入它的目的为协助 std::shared_ptr 工作。
std::weak_ptr 可以从一个 std::shared_ptr 或另一个 std::weak_ptr 对象构造，
std::shared_ptr 可以直接赋值给 std::weak_ptr ，也可以通过 std::weak_ptr 的 lock() 函数来获得 
std::shared_ptr。它的构造和析构不会引起引用计数的增加或减少。
std::weak_ptr 可用来解决 std::shared_ptr 相互引用时的死锁问题
（即两个std::shared_ptr 相互引用，那么这两个指针的引用计数永远不可能下降为 0， 资源永远不会释放）。
*/

/*
既然使用了 std::weak_ptr 的 expired() 方法判断了对象是否存在，
为什么不直接使用 std::weak_ptr 对象对引用资源进行操作呢？
实际上这是行不通的，std::weak_ptr 类没有重写 operator-> 和 operator* 方法，
因此不能像 std::shared_ptr 或 std::unique_ptr 一样直接操作对象，
同时 std::weak_ptr 类也没有重写 operator! 操作，
因此也不能通过 std::weak_ptr 对象直接判断其引用的资源是否存在
#include <memory>

class A
{
public:
    void doSomething()
    {

    }
};

int main()
{    
    std::shared_ptr<A> sp1(new A());

    std::weak_ptr<A> sp2(sp1);

    //正确代码
    if (sp1)
    {
        //正确代码
        sp1->doSomething();
        (*sp1).doSomething();
    }

    //正确代码
    if (!sp1)
    {

    }

    //错误代码，无法编译通过
    //if (sp2)
    //{
    //    //错误代码，无法编译通过
    //    sp2->doSomething();
    //    (*sp2).doSomething();
    //}

    //错误代码，无法编译通过
    //if (!sp2)
    //{

    //}

    return 0;
}
*/

#include <iostream>
#include <memory>

void create(){
    //创建一个std::shared_ptr对象
    std::shared_ptr<int> sp1(new int(123));
    std::cout << "use count: " << sp1.use_count() << std::endl;

    //通过构造函数得到一个std::weak_ptr对象
    std::weak_ptr<int> sp2(sp1);
    std::cout << "use count: " << sp1.use_count() << std::endl;

    //通过赋值运算符得到一个std::weak_ptr对象
    std::weak_ptr<int> sp3 = sp1;
    std::cout << "use count: " << sp1.use_count() << std::endl;

    //通过一个std::weak_ptr对象得到另外一个std::weak_ptr对象
    std::weak_ptr<int> sp4 = sp2;
    std::cout << "use count: " << sp1.use_count() << std::endl;
    //use count: 1
    // use count: 1
    // use count: 1
    // use count: 1
}

int main()
{
    // create();
    return 0;
}
