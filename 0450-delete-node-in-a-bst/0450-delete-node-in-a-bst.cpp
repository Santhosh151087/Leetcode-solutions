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
    //finding left most right here we can also use right most left
    TreeNode* findlast(TreeNode*root){
        if(root->right==nullptr)
        return root;
        return findlast(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        return root;
        if(root->val > key){
            root->left =  deleteNode(root->left , key);
        }
        else if(root->val <key){
            root->right= deleteNode(root->right , key);
        }

        else{
            if(root->left==nullptr)
            return root->right;
            if(root->right==nullptr)
            return root->left;
            else{
                TreeNode* last = findlast(root->left);
                root->val = last->val;
                root->left = deleteNode(root->left , root->val);
                
            }
        }
        return root;
    }
};