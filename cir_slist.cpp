#include<iostream> 
#include<stdlib.h>
using namespace std;
template<typename date_type>
class node{
	public:
	date_type date;
	node *next;
	
};
template<typename date_type>
class cri_slist:public node<date_type>
{
	private:
		node<date_type>* head_node;
		node<date_type>* tail_loc;
		int len;
	public: 
		cri_slist()//缺省的构造函数 
		{
		    head_node=new node<date_type>;
			head_node->next=head_node;
			tail_loc=NULL;
			len=0;
		}
		cri_slist(cri_slist &cop);//拷贝构造函数 
		void print(); 
		bool empty()
		{
			if(head_node->next==head_node)
			 return true;
			else
			 return false;
		}
		void push_back(date_type val);//末尾插入 
		void push_front(date_type val);//从头插入
		node<date_type>* find(date_type val); 
		void insert(node<date_type>* p,date_type val);
		void eraser(node<date_type>* p);
		void eraser(node<date_type>* first,node<date_type>* last);
		int size()
		{
			return len;
		}
};
template<typename date_type>
cri_slist<date_type>::cri_slist(cri_slist &cop)//注意模板类外面格式的写法 
{
	node<date_type>* temp=cop.head_node->next;
	head_node=new node<date_type>;
	head_node->next=head;
	tail_loc=NULL;
	len=0;
	while(temp!=NULL)
	{
				
	 node<date_type>* cop_ele=new node<date_type>;
	 cop_ele->date=temp->date;
	 cop_ele->next=NULL;
     if(!empty())
		{
		    tail_loc->next=cop_ele;
		    tail_loc=cop_ele;
		    tail_loc->next=head_node;
		}
	  else
		   {
		     head_node->next=cop_ele;
			 tail_loc=cop_ele;
			 tail_loc->next=head_node;
		   }	
		temp=temp->next;
		len++;
	}
}
template<typename date_type>
void cri_slist<date_type>::push_back(date_type val)
		{
			node<date_type>* push_ele=new node<date_type>;
			push_ele->date=val;
			push_ele->next=NULL;
		    if(!empty())
		    {
		    	tail_loc->next=push_ele;
		    	tail_loc=push_ele;
		    	tail_loc->next=head_node;
		    }
		    else
		      {
		      	head_node->next=push_ele;
			    tail_loc=push_ele;
			    tail_loc->next=head_node;
			  }	
			len++;
		}
template<typename date_type>
void cri_slist<date_type>::push_front(date_type val)
		{
			node<date_type>* push_ele=new node<date_type>;
			push_ele->date=val;
			push_ele->next=NULL;
			if(!empty())
		    {
		    	push_ele->next=head_node->next;
		    	head_node->next=push_ele;
		    }
		    else
		      {
		      	head_node->next=push_ele;
			    tail_loc=push_ele;
			    tail_loc->next=head_node;
			  }	
			len++;
		}
template<typename date_type>
void cri_slist<date_type>::print()
		{
			node<date_type>* temp=head_node->next;
			while(temp!=head_node)
			{
				cout<<temp->date<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
template<typename date_type>
node<date_type>* cri_slist<date_type>::find(date_type val)
{
	int flag=0;
	node<date_type>* temp=head_node->next;
	node<date_type>* loc=NULL;
	while(temp!=head_node)
	{
		if(temp->date==val)
		{
			loc=temp;
			break;
		}
		temp=temp->next;
	}
	return loc;	
}
template<typename date_type>
void mylist<date_type>::insert(node<date_type> *p,date_type val)//不判断p是否合法 
{
	 node<date_type> *new_ele=new node<date_type>;
	 new_ele->date =val;
	 new_ele->next=p->next; 
	 p->next=new_ele;
	 len++;
}
template<typename date_type>
void mylist<date_type>::eraser(node<date_type> *p)
{
	node<date_type>* temp=head_node;
	while(temp->next!=p)
	  temp=temp->next;
	temp->next=p->next;
	len--;
	free(p);
}
