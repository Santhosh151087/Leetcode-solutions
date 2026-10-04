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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        return {};
        map<int ,int> mp;// level , first node
        queue<pair<TreeNode* ,  int>>qu;
        qu.push({root , 0});
        while(!qu.empty()){
            auto [node , level] = qu.front();
            qu.pop();
           
            mp[level] = node->val;
            if(node->left!=nullptr)
            qu.push({node->left , level+1});
            if(node->right!=nullptr)
            qu.push({node->right  , level+1});

        }
        vector<int> ans;
        for(auto &[key , val] : mp){
            ans.push_back(val);
        }
        return ans;
    }
};