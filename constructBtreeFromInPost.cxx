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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    TreeNode *root = NULL;
    if (inorder.size() == 0) return root;
        
    root = buildTreeImpl(inorder.begin(), inorder.end(), postorder.end() - 1);
    return root;
  }
    
private:
  TreeNode* buildTreeImpl(vector<int>::iterator inBegin, 
			  vector<int>::iterator inEnd, vector<int>::iterator postIt) {
    if (inEnd - inBegin == 0) return NULL;
        
    if (inEnd - inBegin == 1) {
      return new TreeNode(*inBegin);
    }
        
    TreeNode *res = new TreeNode(0);
        
    res->val = *postIt;
    vector<int>::iterator radix = find(inBegin, inEnd, *postIt);
    int index = inEnd - radix;
    res->right = buildTreeImpl(radix + 1, inEnd, postIt - 1);
    res->left = buildTreeImpl(inBegin, radix, postIt - index);
  }
};








