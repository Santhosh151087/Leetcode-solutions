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
    vector<int> arr;
    vector<TreeNode*> ns;
    
    void traverse(TreeNode* root){
        if(root==nullptr)
        return ;
        traverse(root->left);
        arr.push_back(root->val);
        ns.push_back(root);
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
       traverse(root);
       
       sort(arr.begin() , arr.end());
       for(int i=0;i<arr.size();i++){
        // cout<<arr[i]<<" "<<ns[i]->val<<endl;
        if(arr[i] !=ns[i]->val){
            ns[i]->val = arr[i];
        }
       }
       
       
    }
};