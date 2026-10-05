/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> pv;
    vector<TreeNode*> qv;
    vector<TreeNode*> arr;
   void findPath(TreeNode* root , TreeNode * leaf , int node){
        if(root==leaf){
            if(node==1){
                pv = arr;
            }
            else
            qv = arr;
            return;
        }
        if(root->left!=nullptr){
            arr.push_back(root->left);
            findPath(root->left , leaf , node);
            arr.pop_back();
        }
        if(root->right!=nullptr){
            arr.push_back(root->right);
            findPath(root->right , leaf , node);
            arr.pop_back();
        }
        // return arr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        arr.push_back(root);
          findPath(root , p ,1);
         findPath(root , q ,2);
        //  for(TreeNode* cur : pv)cout<<cur->val<<" ";
        //  cout<<endl;
        //  for(TreeNode* cur: qv)cout<<cur->val<<" ";
       int minn = min(pv.size() , qv.size());
        for(int i=minn-1;i>=0;i--){
            if(pv[i]==qv[i])
            return pv[i];
        }
        
        return nullptr;
    }
};