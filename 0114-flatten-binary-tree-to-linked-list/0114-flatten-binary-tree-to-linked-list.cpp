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
    TreeNode* prev = nullptr;
    void solve(TreeNode* root){
        if(root==nullptr)
        return;
        if(prev !=nullptr){
        prev->right = root;  
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
       root->left  = nullptr;
        root->right = nullptr;
        prev = root;
        solve(left);
        solve(right);
        
        
    }
    void flatten(TreeNode* root) {
       
        solve(root);
      

    }
};