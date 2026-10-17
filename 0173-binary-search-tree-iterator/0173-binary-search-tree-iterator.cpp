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
class BSTIterator {
public:
    TreeNode* root ;
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    stack<TreeNode*> st;
    
    int next() {
       while(root!=nullptr){
        st.push(root);
        root = root->left;
       }
      root = st.top();
       st.pop();
       int ans = root->val;
       root = root->right;
       return ans;
       
    }
    
    bool hasNext() {
        if(st.empty() && root==nullptr)
        return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */