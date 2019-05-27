#include<iostream> 
#include"mylist.h"
using namespace std;
int main()
{
    mylist<int> test;
     cout<<test.size()<<'\n';
    test.push_back(5);
     cout<<test.size()<<'\n';
    test.push_back(25);
     cout<<test.size()<<endl;
    test.push_back(29);
     cout<<test.size()<<endl;
    test.push_front(0);
     cout<<test.size()<<endl;
    test.push_front(-25);
     cout<<test.size()<<'\n';
     test.print();
     //
     cout<<" shangmian shi 5"<<'\n';
    node<int> *p=test.find(25) ;
    test.insert(p,500);
    cout<<test.size()<<'\n';
    test.print();
    //
    test.eraser(p);
    cout<<test.size()<<endl;
    test.print();
    mylist<int> b(test);
    cout<<b.size()<<endl;
    b.print();
}
