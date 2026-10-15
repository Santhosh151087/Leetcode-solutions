/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(
 right) {}
 * };
 */

 // for every node we going to set start and end the element must be in the limit 
 // if we are going left means end should be cur and right means start should be cur val
class Solution {
public:
    bool solve(TreeNode* root , long long int start , long long int end){
        if(root==nullptr)
        return true;
        if(root->val <= start || root->val >=end)
        return false;
        return solve(root->left , start , root->val) && solve(root->right , root->val , end);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root , LLONG_MIN , LLONG_MAX);
    }
};