#include"queue.h"
#include<iostream>
using namespace std;
int main()
{
	queue<double> myqueue;
	for(int i=0;i<10;++i)
	 myqueue.push(i+6);
	myqueue.print();
	myqueue.pop();
	myqueue.pop();
	myqueue.print();
}
