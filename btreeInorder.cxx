/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> res;
    if (root == NULL) return res;
        
    stack<TreeNode*> ts;
    ts.push(root);
    TreeNode *p = NULL;
    while (true) {
      p = ts.top();
      if (p != NULL) {
	ts.push(p->left);
                
      } else {
	ts.pop();
	if (ts.empty()) {
	  break;
	} else {
                   
	  p = ts.top();
	  res.push_back(p->val);
	  ts.pop();
	  ts.push(p->right);
	}
      }
    }
    return res;
  }
};
