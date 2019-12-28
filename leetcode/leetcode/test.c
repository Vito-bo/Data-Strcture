

#include<stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//翻转二叉树
struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;
	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}

//求二叉树的最大深度

int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

}

//单值二叉树
void isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
		return true;
	if (root->left && root->left->val != root->val)
		return false;
	if (root->right && root->right->val != root->val)
		return false;

	return isUnivalTree(root->left) && isUnivalTree(root->right);

}

//二叉树的前序遍历
/*Definition for a binary tree node.
* struct TreeNode {
	*int val;
	*struct TreeNode *left;
	*struct TreeNode *right;
	*
};
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/



int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _preorderTraversal(struct TreeNode* root, int* a, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	a[*pi] = root->val;
	++*pi;
	_preorderTraversal(root->left, a, pi);
	_preorderTraversal(root->right, a, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = TreeSize(root);
	int* a = (int*)malloc(sizeof(int)*size);
	int i = 0;
	_preorderTraversal(root, a, &i);

	*returnSize = size;

	return a;
}

//合并二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
	if (t1 == NULL&&t2 == NULL)
		return(NULL);
	if (t1 != NULL&&t2 == NULL)
		return(t1);
	if (t1 == NULL&&t2 != NULL)
		return(t2);
	t1->val = t1->val + t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return(t1);
}