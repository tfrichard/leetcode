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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    TreeNode *root = NULL;
    if (preorder.size() == 0) {
      return root;
    }
        
    root = buildTreeImpl(inorder.begin(), inorder.end(), preorder.begin());
    return root;
  }
    
private:    
  TreeNode *buildTreeImpl(vector<int>::iterator inBegin, vector<int>::iterator inEnd, 
			  vector<int>::iterator preBegin) {
    if (inBegin == inEnd) return NULL;
        
    if (inEnd - inBegin == 1) {
      return new TreeNode(*inBegin);
    }
        
    TreeNode *res = new TreeNode(0);
    vector<int>::iterator radix = find(inBegin, inEnd, *preBegin);
    res->val = *radix;
    res->left = buildTreeImpl(inBegin, radix, preBegin + 1);
    int index = radix - inBegin + 1;
    res->right = buildTreeImpl(radix + 1, inEnd, preBegin + index);
    return res;
  }
};


