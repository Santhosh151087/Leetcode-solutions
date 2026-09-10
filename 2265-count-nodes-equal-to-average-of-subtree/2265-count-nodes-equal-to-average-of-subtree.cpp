/**
 * Definition for a binary tree node->
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
    int ans = 0;
    pair<int , int> solve(TreeNode* root){
        if(root==nullptr){
            return pair<int , int> {0,0};
        }
        if(root->left ==nullptr && root->right==nullptr){
           ans++;
            return pair<int , int> {root->val , 1};
        }
        pair<int , int> lf = solve(root->left);
        pair<int , int> rt = solve(root->right);
        int sum = lf.first + rt.first+root->val;
        int ct = lf.second + rt.second +1;
        if(root->val==(sum/ct))
        ans++;
        return pair<int , int> {sum , ct};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};