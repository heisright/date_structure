#include<iostream>
using namespace std;
template<typename date_type>
class node{
	public:
	 date_type ele;
	 node* front;
	 node* next;
}; 
template<typename date_type>
class doulist:public node<date_type>{
	private:
		node<date_type> *head_node;
		node<date_type> *tail_loc;//方便某个运算 
		int len;
	public:
		doulist();
		doulist(doulist &cop);
		bool empty()
		{
			if(head_node->next==NULL)
			 return true;
			else
			 return false;
		}
		void push_back(date_type val);
		void push_front(date_type val);
		node<date_type>* find(date_type val);
		void insert(node<date_type>* p,date_type val);
		void eraser(node<date_type> *p);
		int size()
		{
			return len;
		}
		void print()
		{
			node<date_type>* temp=head_node->next;
			while(temp!=NULL)
			{
				cout<<temp->ele<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
template<typename date_type>
doulist<date_type>::doulist()
{
	head_node=new node<date_type>;
	head_node->next=NULL;
	head_node->front=NULL;
	tail_loc=NULL;
	head_node->ele=-1;//可以不设置 
	len=0;
}
template<typename date_type>
doulist<date_type>::doulist(doulist &cop)
{
	node<date_type> *temp=cop.head_node->next;
	head_node=new node<date_type>;
	head_node->next=NULL;
	head_node->front=NULL;
	tail_loc=NULL;
	head_node->ele=-1;
	while(temp!=NULL)
	{
		node<date_type>* cop_node=new node<date_type>;
		cop_node->ele=temp->ele;
		cop_node->next=NULL;
		if(!empty())
		{
			tail_loc->next=cop_node;
			cop_node->front=tail_loc;
		}
		else
		{
			head_node->next=cop_node;
			cop_node->front=head_node;
			tail_loc=cop_node;
		}
		temp=temp->next;
		len++;
	}
	
 } 
 template<typename date_type>
 void doulist<date_type>::push_back(date_type val)
 {
 	node<date_type>* new_node=new node<date_type>;
 	new_node->ele=val;
 	if(!empty())
 	{
    	tail_loc->next=new_node;
	    new_node->front=tail_loc;
	}
	else
	{
			head_node->next=new_node;
			new_node->front=head_node;
			tail_loc=new_node;
	}
	len++;
 }
 template<typename date_type>
 void doulist<date_type>::push_front(date_type val)
 {
 	node<date_type>* new_node=new node<date_type>;
 	new_node->ele=val;
 	if(!empty())
 	{
	    new_node->next=head_node->next;
	    new_node->front=head_node;
	    head_node->next=new_node;
	}
	else
	{
			head_node->next=new_node;
			new_node->front=head_node;
			tail_loc=new_node;
	}
	len++;
 }
 template<typename date_type>
 node<date_type>* doulist<date_type>::find(date_type val)
 {
 	node<date_type>* temp=head_node->next,*ans=NULL;
 	while(temp!=NULL)
 	{
 		if(temp->ele==val)
 		{
 			ans=temp;
 			break;
		 }
		 temp=temp->next;
	 }
	 return ans;
 }
 template<typename date_type>
 void doulist<date_type>::insert(node<date_type>* p,date_type val)
 {
   	node<date_type> *new_ele=new node<date_type>;
   	new_ele->ele=val;
	new_ele->next=p->next;
	new_ele->front=p;
	if(p->next==NULL)
	 p->next=new_ele;
	else
	{
		p->next->front=new_ele;
		p->next=new_ele;
	}
	 len++;
 }
 template<typename date_type>
 void doulist<date_type>::eraser(node<date_type> *p)
 {
 	p->front->next=p->next;
 	p->next->front=p->front;
 	len--;
	free(p);
 }
	
