#include"stack.h"
#include<iostream>
using namespace std;
int main()
{
	stack<int> mystack;
	mystack.pop();
	for(int i=0;i<10;++i)
	 mystack.push(i+5);
	mystack.print();
	mystack.pop();
	mystack.print();
	cout<<mystack.top()<<endl;
}
