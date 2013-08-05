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
  int maxPathSum(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL) return 0;
    int max = -9999999;
    maxPathImpl(root, max);
    return max;
  }
    
private:
  int maxPathImpl(TreeNode *root, int &res) {
    if (root->left == NULL && root->right == NULL) {
      if (root->val > res)
	res = root->val;
      return root->val;
    }
        
    int localMax = root->val;
    int leftMax;
    int rightMax;
    int subMax;
    if (root->left != NULL && root->right == NULL) {
      leftMax = maxPathImpl(root->left, res);
      subMax = max(leftMax + root->val, root->val);
      if (subMax > res) res = subMax;
      return subMax;
    } else if (root->right != NULL && root->left == NULL) {
      rightMax = maxPathImpl(root->right, res);
      subMax = max(rightMax + root->val, root->val);
      if (subMax > res) res = subMax;
      return subMax;
    } else {
      leftMax = maxPathImpl(root->left, res);
      rightMax = maxPathImpl(root->right, res);
      subMax = max(rightMax + root->val, max(leftMax + root->val, root->val));
      localMax = max(subMax, leftMax + rightMax + root->val);
      if (localMax > res) res = localMax;
      return subMax;
    }
         
  }
};
