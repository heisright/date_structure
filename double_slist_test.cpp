#include"double_slist.h"
using namespace std;
int main()
{
	doulist<int> test1,test2;
	test1.push_back(25);
	test1.push_front(36);
	node<int> *p=test1.find(25);
	test1.insert(p,100);
	test1.print();
	return 0;
}
