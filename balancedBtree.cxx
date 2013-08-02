class Solution {
public:
  bool isBalanced(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (root == NULL) return true;
        
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
  }
    
private:
  int height(TreeNode *root) {
    if (root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
  }
};
