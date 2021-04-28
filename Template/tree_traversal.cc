void preorder(TreeNode* root) {
	if (root == nullptr)
	    return;

	visit(root->val);
	preorder(root->left, ans);
	preorder(root->right, ans);
}
void preorder(TreeNode* root) {
	if (root == nullptr)
		return;

	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode* tmp = stk.top();
		stk.pop();
		visit(tmp->val);
		if (tmp->right)
			stk.push(tmp->right);
		if (tmp->left)
			stk.push(tmp->left);	
	}
}
void inorder(TreeNode* root) {
	if (root == nullptr)
	    return;
	
	inorder(root->left, ans);
	visit(root->val);
	inorder(root->right, ans);
}
void inorder(TreeNode* root) {
	if (root == nullptr)
		return;
	
	stack<TreeNode*> stk;
	TreeNode* cur = root;
	while (cur != nullptr || !stk.empty()) {
		if (cur) {
			stk.push_back(cur);
			cur = cur->left;	
		} else {
			TreeNode* tmp = stk.top();
			stk.pop();
			visit(tmp->val); // left, mid
			cur = tmp->right;// right
		}	
	}	
}
void postorder(TreeNode* root) {
	if (root == nullptr)
	    return;
	
	postorder(root->left, ans);
	postorder(root->right, ans);
	visit(root->val);
}

void levelorder(TreeNode* root) {
	if (root == nullptr)
		return;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		visit(tmp->val);
		if (tmp->left)
			q.push(tmp->left);
		if (tmp->right)
			q.push(tmp->right);	
	}
}
