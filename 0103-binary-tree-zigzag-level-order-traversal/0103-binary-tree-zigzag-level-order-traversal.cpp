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
    vector<vector<int>> ans;
    void solve(TreeNode* root){
        if(root==nullptr)
        return;
        queue<TreeNode*> qu;
        qu.push(root);
        int count=0;
        while(!qu.empty()){
            int size = qu.size();
            vector<int> c;
            for(int i=0;i<size;i++){
                TreeNode* cur = qu.front();
                c.push_back(cur->val);
                qu.pop();
                if(cur->left!=nullptr)
                qu.push(cur->left);
                if(cur->right!=nullptr)
                qu.push(cur->right);
            }
            if(count%2==1)
            reverse(c.begin() , c.end());
            ans.push_back(c);
            count++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root);
        return ans;
    }
};