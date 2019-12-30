

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef char BTDataType;
typedef struct BinaryTreeNode 
{ 
	BTDataType _data;    
	struct BinaryTreeNode* _left;    
	struct BinaryTreeNode* _right; 
}BTNode;



// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi); 

// 二叉树销毁 
void BinaryTreeDestory(BTNode** root); 

// 二叉树节点个数,后序算法求节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数 
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if(root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数 
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{

}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

}

// 二叉树中序遍历 
void BinaryTreeInOrder(BTNode* root); 

// 二叉树后序遍历 
void BinaryTreePostOrder(BTNode* root); 

// 层序遍历 
void BinaryTreeLevelOrder(BTNode* root); 

// 判断二叉树是否是完全二叉树 
int BinaryTreeComplete(BTNode* root); 