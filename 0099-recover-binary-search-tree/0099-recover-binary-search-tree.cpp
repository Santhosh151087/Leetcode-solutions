/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* mid = nullptr;
        TreeNode* last = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(!st.empty() || cur!=nullptr){
            while(cur!=nullptr){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if(prev!=nullptr){
               if(prev->val > cur->val){
                    if(first==nullptr){
                        first = prev;
                        mid = cur;
                    }
                    else{
                int temp = first->val;
                first->val  = cur->val;
                cur->val = temp;
                        return;
                    }
                }
            }
            prev = cur;
            cur = cur->right;
             }
             if(first==nullptr)
             return;
              int temp = first->val;
                first->val  = mid->val;
                mid->val = temp;
    }
};