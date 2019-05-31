#include<iostream>
using namespace std;
template<typename date_type>
class node{
	public:
	date_type ele;
	node *next;
};
template<typename date_type>
class stack:public node<date_type>{
	private:
    	node<date_type> *base;
		node<date_type> *top_loc;
		int len;
	public:
		stack();
		bool empty();
		void push(date_type val);
		date_type top();
		void pop();
		void print();//至少为了验证操作的正确性 
};
template<typename date_type>
stack<date_type>::stack()
{
	base=new node<date_type>;
	base->next=NULL;
	top_loc=base;
	len=0;
}
template<typename date_type>
bool stack<date_type>::empty()
{
	if(base==top_loc)
	  return true;
	else
	  return false;
}
template<typename date_type>
void stack<date_type>::push(date_type val)
{
	node<date_type> *temp=new node<date_type>;
	temp->ele=val;
	temp->next=NULL;
	top_loc->next=temp;
	top_loc=top_loc->next;
	len++;
}
template<typename date_type>
date_type stack<date_type>::top()
{
	if(!empty())
	  return top_loc->ele;
	else
	 {
	 	 cout<<"wrong the stack is empty\n";
	 	 exit(0);;
	 }
}
template<typename date_type>
void stack<date_type>::pop()
{
	if(!empty())
	{
      	node<date_type>* temp=base;
		while(temp->next!=top_loc)
	  	    temp=temp->next;
		top_loc=temp;
		top_loc->next=NULL;
    }
    else
    {
    	cout<<"wrong the stack is empty\n";
    	exit(0);
	}
 } 
 template<typename date_type>
 void stack<date_type>::print()
 {
 	node<date_type> *temp=base->next;
 	while(temp!=NULL)
 	{
 		cout<<temp->ele<<" ";
 		temp=temp->next;
    }
 	cout<<endl;
 	
 }
