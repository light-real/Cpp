#include<memory>
#include<iostream>

using namespace std;

/*
std::unique_ptr 对其持有的资源具有独占性，而 std::shared_ptr 持有的资源可以在多个 std::shared_ptr 之间共享，
每多一个 std::shared_ptr 对资源的引用，资源引用计数将增加 1，
每一个指向该资源的 std::shared_ptr 对象析构时，资源引用计数减 1，
最后一个 std::shared_ptr 对象析构时，发现资源计数为 0，将释放其持有的资源。
多个线程之间，递增和减少资源的引用计数是安全的。（注意：这不意味着多个线程同时操作 std::shared_ptr 引用的对象是安全的）。
std::shared_ptr 提供了一个 use_count() 方法来获取当前持有资源的引用计数。
除了上面描述的，std::shared_ptr 用法和 std::unique_ptr 基本相同。
*/
class A{
public:
    A(){
        cout<<"constructor"<<endl;
    };
    ~A(){
        cout<<"destrctor"<<endl;
    };
};

void create(){
    shared_ptr<A> sp1(new A());
    cout<<"sp1.use_count is "<< sp1.use_count()<<endl;

    shared_ptr<A> sp2(sp1);
    cout<<"sp1.use_count is "<< sp1.use_count()<<endl;
}



int main(){

    create();
    return 0;
}
