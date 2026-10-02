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
    int findLen(TreeNode* root){
        if(root==nullptr)
        return 0;
        int left = findLen(root->left);
        int right = findLen(root->right);
        return 1+max(left , right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        return 0;

        int left = findLen(root->left);
        int right = findLen(root->right);
        int curd  = left+right;
        int leftd = diameterOfBinaryTree(root->left);
        int rightd = diameterOfBinaryTree(root->right);
        return max(curd , max(leftd,rightd));
    }
};