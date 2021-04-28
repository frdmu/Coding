void preorder(TreeNode* root) { // inorder, postorder
	if (root == nullptr)
	    return;

	visit(root->val);// mid
	preorder(root->left, ans);// left
	preorder(root->right, ans);// right
}
void preorder(TreeNode* root) { // inorder, postorder
	if (root == nullptr)
		return;

	stack<TreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		TreeNode* tmp = stk.top();
		stk.pop();
		if (tmp) {// push
			if (tmp->right)
				stk.push(tmp->right);// right

			if (tmp->left)
				stk.push(tmp->left); // left	

			stk.push(tmp);
			stk.push(NULL); // mid
		} else {// visit
			TreeNode* tmp = stk.top();
			stk.pop();
			visit(tmp->val);	
		}	
	}
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
