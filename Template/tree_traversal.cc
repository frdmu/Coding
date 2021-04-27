void preorder(TreeNode* root) {
	if (root == nullptr)
	    return;

	visit(root->val);
	preorder(root->left, ans);
	preorder(root->right, ans);
}
void inorder(TreeNode* root) {
	if (root == nullptr)
	    return;
	
	inorder(root->left, ans);
	visit(root->val);
	inorder(root->right, ans);
}
void postorder(TreeNode* root) {
	if (root == nullptr)
	    return;
	
	postorder(root->left, ans);
	postorder(root->right, ans);
	visit(root->val);
}
