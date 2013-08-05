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
  vector<vector<int> > levelOrder(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    queue<TreeNode*> level;
    vector<vector<int> > res;
    if (root == NULL) return res;
        
    level.push(root);
    level.push(NULL);
    while (!level.empty()) {
      vector<int> tmp;
      TreeNode *p = level.front();
      if (p == NULL) break;
            
      while (p != NULL) {
	tmp.push_back(p->val);
                
	if (p->left != NULL) level.push(p->left);
	if (p->right != NULL) level.push(p->right);
	level.pop();
	p = level.front();
      }
      level.pop();
            
      res.push_back(tmp);
      level.push(NULL);
    }
        
    return res;
  }
};
