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
  TreeNode *sortedArrayToBST(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    TreeNode *root = NULL;
    if (num.size() == 0) return root;
        
    root = convertImpl(num.begin(), num.end());
    return root;
  }
    
  TreeNode *convertImpl(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin == end) return NULL;
        
    if (end - begin == 1) return new TreeNode(*begin);
        
    vector<int>::iterator mid = begin +  (end - begin) / 2;
    TreeNode *res = new TreeNode(*mid);
    res->left = convertImpl(begin, mid);
    res->right = convertImpl(mid + 1, end);
    return res;
  }
};




