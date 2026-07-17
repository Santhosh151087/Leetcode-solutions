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
    // TreeNode* prev;
    TreeNode* findLast(TreeNode* root){
     if (root->right == nullptr) {
           
            return root;
        }
    // prev = root;
    return findLast(root->right);
}
   
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        return root;
        if(root->val > key)
        root->left = deleteNode(root->left , key);
        else if(root->val <key)
        root->right = deleteNode(root->right , key);
        else{
            if(root->left == nullptr)
            return root->right;
            else if(root->right ==nullptr)
            return root->left;
            else{
               
                TreeNode* last = findLast(root->left);
                root->val = last->val;
                root->left = deleteNode(root->left , root->val);
                
            }
        }
        return root;
    }
};