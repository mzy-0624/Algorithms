#define Max 200
int pre[Max] = { 0 }, in[Max] = { 0 };		// preorder and inorder traversal
struct node {
	node* left;			// left child
	node* right;		// right child
    node* pa;			// parent
};
node* reconstruct(int pre_l, int pre_r, int in_l, int in_r)
{
	if (pre_l > pre_r || in_l > in_r)
		return NULL;
	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	int num = in_l;
	while (in[num] != pre[pre_l])
		num++;
	ptr->left = reconstruct(pre_l + 1, pre_l + num - in_l, in_l, num - 1);
	ptr->right = reconstruct(pre_l + num - in_l + 1, pre_r, num + 1, in_r);
	return ptr;
}
