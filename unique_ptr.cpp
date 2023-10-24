#include<iostream>
#include<memory>
using namespace std;

/*
鉴于 std::auto_ptr 的前车之鉴，std::unique_ptr 禁止复制语义
为了达到这个效果，std::unique_ptr 类的拷贝构造函数和赋值运算符（operator =）被标记为 delete
template <class T>
class unique_ptr
{
    //省略其他代码...

    //拷贝构造函数和赋值运算符被标记为delete
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
};

std::unique_ptr<int> sp1(std::make_unique<int>(123));;

//以下代码无法通过编译  拷贝构造函数和赋值操作是无法通过编译的
//std::unique_ptr<int> sp2(sp1); 
std::unique_ptr<int> sp3;
//以下代码无法通过编译
//sp3 = sp1;
*/


void create(){
    /*
    std::unique_ptr 对其持有的堆内存具有唯一拥有权，也就是说引用计数永远是 1
    std::unique_ptr 对象销毁时会释放其持有的堆内存。可以使用以下方式初始化一个 std::unique_ptr 对象：*/
    
    unique_ptr<int> sp1(new int(8));  //创建方式1
    
    unique_ptr<int> sp2;
    sp2.reset(new int(8));   // 创建方式2

    unique_ptr<int> sp3 = make_unique<int>(123);  //创建方式3

    if(sp1.get() && sp2.get() && sp3.get()){
        cout<<"create is successful"<<endl;
    }
}

void transfer(){
    //将unique_ptr对象持有的堆内存转移给另一个
    //使用的方法是通过移动构造


    /*
    以上代码利用 std::move 将 sp1 持有的堆内存（值为 123）转移给 sp2，再把 sp2 转移给 sp3。
    最后，sp1 和 sp2 不再持有堆内存的引用，变成一个空的智能指针对象。并不是所有的对象的 std::move 操作都有意义，
    只有实现了移动构造函数（Move Constructor）或移动赋值运算符（operator =）的类才行，
    而 std::unique_ptr 正好实现了这二者
    */
    unique_ptr<int> sp1(make_unique<int>(8));
    unique_ptr<int> sp2(move(sp1));
    unique_ptr<int> sp3;
    sp3 = move(sp2);

    if(sp1.get() == NULL){
        cout<<"sp1 is NULL"<<endl;
    }
    else{
        cout<<"sp1 is not NULL"<<endl;
    }
    //sp1 is NULL
}

int main(){
    // create();
    transfer();
    return 0;
}
