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
 class Iterator{
    stack<TreeNode*> st;
    bool rev = true;
    // rev -> true -> back
    // rev-> false -> front
    public:
    Iterator(TreeNode* _root , bool _rev){
        
        this->rev  = _rev;
        pushAll(_root);
    }
    private:
    void pushAll(TreeNode* root){
        while(root!=nullptr){
            st.push(root);
            if(rev){
                root = root->right;
            }else{
                root = root->left;
            }
        }
     }
     public:
     int next(){
        TreeNode* cur = st.top();
        st.pop();
        if(rev){
            pushAll(cur->left);
        }
        else{
            pushAll(cur->right);
        }
        return cur->val;
     }
 };
class Solution {
public:
     bool findTarget(TreeNode* root, int k) {
        if(!root)
        return false;
        Iterator l(root , false);
        Iterator r(root , true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j ==k)
            return true;
            else if(i+j < k){
                i = l.next();
            }
            else
            j = r.next();
        }
        return false;
    }
};