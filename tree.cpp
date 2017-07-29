#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cassert>

typedef struct bin_tree_node{
	int _value;
	bin_tree_node *_pleft;
	bin_tree_node *_pright;
}btree_node;

btree_node *construct_core(int *pre,int *pre_lenth,int *ino,int *ino_lenth){
	btree_node *node = new btree_node();
	assert(node != NULL);

	node->_value = pre[0];
	node->_pleft = NULL;
	node->_pright = NULL;

	int *root_ino = ino;
	while(root_ino <= ino_lenth && node->_value != *root_ino ){
		++root_ino;	
	}

	int left_lenth = root_ino - ino;
	int *left_end = pre + left_lenth;

	if(left_lenth > 0){
		node->_pleft = construct_core(pre + 1,left_end,ino,root_ino - 1);
	}
	if(left_lenth < pre_lenth - pre){
		node->_pright = construct_core(left_end + 1,pre_lenth,root_ino + 1,ino_lenth);
	}

	return node;
}

btree_node *my_print_pre(btree_node *root){
	if(root == NULL){
		return NULL;
	}
	std::cout<<root->_value;
	if(root->_pleft != NULL){
		my_print_pre(root->_pleft);
	}
	if(root->_pright != NULL){
		my_print_pre(root->_pright);
	}

	return NULL;
}

btree_node *my_print_post(btree_node *root){
	if(root == NULL){
		return NULL;
	}
	if(root->_pleft != NULL){
		my_print_post(root->_pleft);
	}
	if(root->_pright != NULL){
		my_print_post(root->_pright);
	}
	std::cout<<root->_value;

	return NULL;
}

btree_node *my_print_ino(btree_node *root){
	if(root == NULL){
		return NULL;
	}
	if(root->_pleft != NULL){
		my_print_ino(root->_pleft);
	}
	std::cout<<root->_value;
	if(root->_pright != NULL){
		my_print_ino(root->_pright);
	}

	return NULL;
}

int main(){
	int pre[] = {1,2,4,7,3,5,6,8};
	int ino[] = {4,7,2,1,5,3,8,6};
	
	btree_node *root;
	int lenth = sizeof(pre)/sizeof(int);

	root = construct_core(pre,pre+lenth-1,ino,ino+lenth-1);

	my_print_post(root);
}
