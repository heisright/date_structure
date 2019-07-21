#include<iostream>
#include"bi_node.h"
using namespace std;
int main()
{

	 bi_tree test;
	 in_th_creat(test.root);
	 in_th_trav(test.root);
	 cout<<endl;
	 /*in_trav(test.root);
	 cout<<endl;
	 post_trav(test.root);
	 cout<<endl;
	 pre_trav_non_recursive(test.root);
	 in_trav_non_recursive(test.root);
	 level_trav(test.root);
	 post_trav_non_recursive(test.root);*/
	return 0;
}
