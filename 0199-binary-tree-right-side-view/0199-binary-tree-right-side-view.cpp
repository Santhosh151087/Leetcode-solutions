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
        vector<int> ans;
        if(root ==nullptr)
        return ans;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int len  = qu.size();
            for(int i=0;i<len;i++){
                TreeNode* cur = qu.front();
                qu.pop();
                if(i==len-1)
                ans.push_back(cur->val);
                if(cur->left!=nullptr)
                qu.push(cur->left);
                if(cur->right !=nullptr)
                qu.push(cur->right);
            }
        }
        return ans;

    }
};