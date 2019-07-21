#include<iostream>
#include<stack> 
#include<queue>
#include<algorithm>
using namespace std;
class bi_node{
	public:
	int ele;
	int left_th;//�������������õ� 
	int	 right_th;
	bi_node *left;
	bi_node *right;
}; 
class bi_tree:public bi_node{
	public:
	bi_node *root;
	bi_tree()//�Լ���ʼ���������ģ�ֻΪ�˷��������Ը��ֺ����� 
	{
	   root=new bi_node;
		bi_node *node_2=new bi_node;
		bi_node *node_3=new bi_node;
		bi_node *node_4=new bi_node;
		bi_node *node_5=new bi_node;
		root->ele=1;
		root->left=node_2;
		root->right=node_3;
		node_2->ele =2;
		node_2->left=node_4;
    	node_2->right=NULL;
		node_3->ele =3;
		node_3->left=NULL;
		node_3->right=node_5;
		node_4->ele =4;
    	node_4->left=NULL;
    	node_4->right=NULL;
		node_5->ele =5;
		node_5->left=NULL;
    	node_5->right=NULL;
		/*        1
		        /  \
		      /     \
		      2      3
		    /         \
		  /            \
		  4             5
		  */
	}
	friend void pre_trav(bi_node  *root);
	friend void in_trav(bi_node  *root);
	friend void post_trav(bi_node  *root);// �ݹ�������
	friend void pre_trav_non_recursive(bi_node  *root);//�ǵݹ�ǰ����� 
	friend void in_trav_non_recursive(bi_node  *root);
	friend void level_trav(bi_node* root);
	friend void post_trav_non_recursive(bi_node  *root);
};
void pre_trav(bi_node  *root)// �ݹ�ǰ����� 
{
	if(root!=NULL)
	{
	 cout<<root->ele<<" ";
	 pre_trav(root->left);
	 pre_trav(root->right);
    }
	else
	  return ;
}
void in_trav(bi_node  *root)// �ݹ��������
{
	if(root!=NULL)
	{
		in_trav(root->left);
		cout<<root->ele<<" ";
		in_trav(root->right);
	}
	else
	  return ;
}
void post_trav(bi_node  *root)// �ݹ�������
{
	if(root!=NULL)
	{
		post_trav(root->left);
		post_trav(root->right);
		cout<<root->ele<<" ";
	}
	else
	 return ;
}
void pre_trav_non_recursive(bi_node  *root)
{
	stack<bi_node> node_stack;
	bi_node *p=root;
	cout<<"����ǵݹ�����Ľ��\n";
	while(p!=NULL||!node_stack.empty())
	{
		if(p!=NULL)
		{
			cout<<p->ele <<" ";
			node_stack.push(*p);
			p=p->left;
	    }
	    else
	    {
	    	p=&node_stack.top();
	    	node_stack.pop();
	    	p=p->right;
		}
	}
	cout<<endl;
	 
}
void in_trav_non_recursive(bi_node  *root)
{
	stack<bi_node> node_stack;
	bi_node *p=root;
	cout<<"����ǵݹ�������\n";
	while(p!=NULL||!node_stack.empty())
	{
		if(p!=NULL)
		{
			node_stack.push(*p);
			p=p->left;
		}
		else
		{
			p=&node_stack.top();
			cout<<p->ele<<" ";
			node_stack.pop();
			p=p->right;
		}
	}
	cout<<endl;
}
void level_trav(bi_node* root)
{
	queue<bi_node> node_queue;
	bi_node *p=NULL;
	cout<<"����������\n";
	if(root!=NULL)
    	node_queue.push(*root);
	while(!node_queue.empty())
	{
		p=&node_queue.front();
		cout<<p->ele <<" ";
		if(p->left!=NULL)
		  node_queue.push(*p->left);
		if(p->right!=NULL)
		   node_queue.push(*p->right);
		node_queue.pop();
	}
	cout<<endl;
}


bi_node *in_pre=NULL;
bi_node *pre_pre=NULL;
bi_node *post_pre=NULL;//����ǰ�ڵ��ǰһ���ڵ� 
void in_th_creat(bi_node *root)//������������������ 
{
	if(root!=NULL)
	
	{
		in_th_creat(root->left);
		if(root->left==NULL)
		  root->left_th=1;
		if(root->right==NULL)
		  root->right_th=1;
		if(in_pre!=NULL)
		{
			if(in_pre->right_th==1)
			{
			  in_pre->right=root;
		 	}
			if(root->left_th==1)
			{
			   root->left=in_pre;
			} 
		}
		in_pre=root;
		in_th_creat(root->right);
	}
}
bi_node* in_th_next(bi_node *p)//���������������ڵ�p�ĺ�̽ڵ� 
{
	if(p!=NULL)
	{
		if(p->right_th==1)
		  return p->right;
		else
		{
			p=p->right;
			while(p->left_th==0)
			  p=p->left;
			return p;
		}
			
	}
	return NULL;
}
bi_node* in_th_pre(bi_node *p)//���������������ڵ�p��ǰ���ڵ� 
{
	if(p!=NULL)
	{
		if(p->left_th==1)
		  return p->left;
		else
		{
			p=p->left;
			while(p->right_th==0)
			  p=p->right;
			return p;
		}
	}
	return NULL;
}
void in_th_trav(bi_node *root)
{
	if(root!=NULL)
	{
		while(root->left_th==0)//���������еĵ�һ���ڵ� 
		 root=root->left;
		do{
			cout<<root->ele<<"  ";
			root=in_th_next(root); //���̽ڵ� 
		}
		while(root!=NULL);
	}
	
}


