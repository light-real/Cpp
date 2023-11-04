#include<iostream>
using namespace std;

//函数模板用typename 
//类模板用class 
//可以为类的成员函数创建函数模板 但是不能是虚函数和析构函数 

//函数模板如果是没有指定参数类型的话，是不支持隐式类型转换的
//函数模板如果指定的参数的类型，支持隐式类型转换 

//函数模板是支持重载的

//函数模板支持自定义数据类型 

//函数模板


//函数模板
template<typename T>
void Swap(T &a,T &b){
	T temp = a;
	a = b;
	b = temp;
} 

int main(){
	int a = 3;
	int b = 4;
	Swap(a,b);
	cout<<a<<"is a"<<endl;
	cout<<b<<"is b"<<endl;
	return 0;
}
