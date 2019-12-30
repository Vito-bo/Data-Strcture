

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



// ͨ��ǰ�����������"ABD##E#H##CF##G##"���������� 
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi); 

// ���������� 
void BinaryTreeDestory(BTNode** root); 

// �������ڵ����,�����㷨��ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ���� 
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if(root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ���� 
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ� 
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{

}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

}

// ������������� 
void BinaryTreeInOrder(BTNode* root); 

// ������������� 
void BinaryTreePostOrder(BTNode* root); 

// ������� 
void BinaryTreeLevelOrder(BTNode* root); 

// �ж϶������Ƿ�����ȫ������ 
int BinaryTreeComplete(BTNode* root); 