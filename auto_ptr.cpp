#include<memory>  //智能指针头文件
#include<iostream>

//创建智能指针测试
void create(){  
    //智能指针创建在堆上
    std::auto_ptr<int> sp1(new int(8));  //第一种创建方式
    std::auto_ptr<int> sp2; //第二种创建方式
    sp2.reset(new int(8));
    if(sp1.get()!=NULL){
        std::cout<<"sp1 is not empty!"<<std::endl;
    }
}

void copy(){
    //auto_ptr<int> sp 
    /*
    std::auto_ptr 真正让人容易误用的地方是其不常用的复制语义
    即当复制一个 std::auto_ptr 对象时（拷贝复制或 operator = 复制）
    原对象所持有的堆内存对象也会转移给复制出来的对象 即原对象变为空
    */
    
    using namespace std;
    auto_ptr<int> sp1(new int(8));
    auto_ptr<int> sp2(sp1); //通过拷贝构造函数赋值
    if(sp1.get() != NULL ){
        cout<<"sp1 is not NULL"<<endl;
    }
    else{
        cout<<"sp1 is NULL"<<endl;
    }

    if(sp2.get() != NULL ){
        cout<<"sp2 is not NULL"<<endl;
    }
    else{
        cout<<"sp2 is NULL"<<endl;
    }

    auto_ptr<int> sp3(new int(8));
    auto_ptr<int> sp4; //通过=赋值
    sp4 = sp3;
    if(sp3.get() != NULL ){
        cout<<"sp3 is not NULL"<<endl;
    }
    else{
        cout<<"sp3 is NULL"<<endl;
    }

    if(sp4.get() != NULL ){
        cout<<"sp4 is not NULL"<<endl;
    }
    else{
        cout<<"sp4 is NULL"<<endl;
    }

    /*
    sp1 is NULL
    sp2 is not NULL
    sp3 is NULL
    sp4 is not NULL
    */
}


int main(){
    create();
    copy();
    return 0;
}
