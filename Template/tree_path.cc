// Get all the paths from root to leaf
void preOrder(TreeNode* root, vector<int> &path, vector<vector<int> > &ans) {
	path.push_back(root->val);
	if (!root->left && !root->right) {
		ans.push_back(path);
		return;
	}

	if (root->left) {
		preOrder(root->left, path, ans);
		path.pop_back();
	}
	if (root->right) {
		preOrder(root->right, path, ans);
		path.pop_back();
	}
}

void main() {
	if (root == nullptr)
		return;
	preOrder(root, path, ans);
}
