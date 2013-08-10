/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    TreeNode *root = NULL;
    if (head == NULL) return root;
        
    root = convertImpl(head);
    return root;
  }
    
  TreeNode *convertImpl(ListNode *head) {
    ListNode *prev = head;
    ListNode *slow = head;
    ListNode *fast = head;
        
    if (head == NULL) return NULL;
    //only one node left
    if (fast->next == NULL) return new TreeNode(slow->val);
        
    if (fast->next->next == NULL) {
      TreeNode *res = new TreeNode(fast->val);
      res->right = new TreeNode(fast->next->val);
      return res;
    }
        
        
    while (fast != NULL) {            
      if (fast->next == NULL) break;
      prev = slow;
      slow = slow->next;
      fast = fast->next;
      fast = fast->next;
    }
        
    TreeNode *res = new TreeNode(slow->val);
    ListNode *begin = slow->next;
    prev->next = NULL;
    //slow->next = NULL;
        
    res->left = convertImpl(head);
    res->right = convertImpl(begin);
    return res;
  }
};





