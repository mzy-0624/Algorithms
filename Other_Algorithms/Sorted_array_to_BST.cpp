#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* helper(vector<int>& nums, int left, int right) 
{
	if (left > right)
		return NULL;
	int mid = right - (right - left) / 2;
	TreeNode* root = new TreeNode(nums[mid]);
	root->left = helper(nums, left, mid - 1);
	root->right = helper(nums, mid + 1, right);
	return root;
}

TreeNode* Sorted_array_to_BST(vector<int>& nums) 
{
	return helper(nums, 0, nums.size() - 1);
}

int main(void)
{
	/* codes */
	return 0;
}
