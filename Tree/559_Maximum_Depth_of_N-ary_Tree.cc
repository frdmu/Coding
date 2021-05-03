// https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) 
            return 0;
        
        int depth = 0; 
        int child = root->children.size();
        for (int i = 0; i < child; i++) {
            depth = max(depth, maxDepth(root->children[i]));
        }        

        return depth+1;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) 
            return 0;
        
        int depth = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            depth++;
            for (int i = 0; i < len; i++) {
                Node* tmp = q.front();
                q.pop();
                int child = tmp->children.size();
                for (int j = 0; j < child; j++) {
                    q.push(tmp->children[j]);
                }
            }
        }

        return depth;
    }
};
