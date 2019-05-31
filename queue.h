#include<iostream>
using namespace std;
template<typename date_type>
class node{
	public:
	date_type ele;
	node *next;
};
template<typename date_type>
class queue:public node<date_type>{
	private:
    	node<date_type> *front;//指向第一个节点的前一个 
		node<date_type> *last;//指向最后一个节点 
		int len;
	public:
		queue();
		bool empty();
		void push(date_type val);
		date_type top();
		void pop();
		void print();//至少为了验证操作的正确性 
};
template<typename date_type>
queue<date_type>::queue()
{
	front=new node<date_type>;
	front->next=NULL;
	last=front;
	len=0;
}
template<typename date_type>
bool queue<date_type>::empty()
{
	if(front==last)
	  return true;
	else
	  return false;
}
template<typename date_type>
void queue<date_type>::push(date_type val)
{
	node<date_type> *temp=new node<date_type>;
	temp->ele=val;
	temp->next=NULL;
	last->next=temp;
	last=last->next;
	len++;
}
template<typename date_type>
date_type queue<date_type>::top()
{
	if(!empty())
	  return front->next->ele;
	else
	 {
	 	 cout<<"wrong the queue is empty\n";
	 	 exit(0);;
	 }
}
template<typename date_type>
void queue<date_type>::pop()
{
	if(!empty())
	{
      	node<date_type> *temp=front->next;
      	if(temp->next!=NULL)
      	 front->next=temp->next;
      	else
      	 front->next=NULL;
    }
    else
    {
    	cout<<"wrong the queue is empty\n";
    	exit(0);
	}
 } 
 template<typename date_type>
 void queue<date_type>::print()
 {
 	node<date_type> *temp=front->next;
 	while(temp!=NULL)
 	{
 		cout<<temp->ele<<" ";
 		temp=temp->next;
    }
 	cout<<endl;
 	
 }
