#include<iostream>
using namespace std;

//函数模板用typename 
//类模板用class 


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
