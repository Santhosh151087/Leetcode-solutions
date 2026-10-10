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
    TreeNode* solve(vector<int>& postorder , int ps , int pe , vector<int> &inorder   ,int is , int ie , map<int,int> &imp){
        if(ps>pe || is > ie)
        return nullptr;
        TreeNode* node = new TreeNode(postorder[pe]);
        int iroot = imp[postorder[pe]];
        int ileft = iroot - is;
        int iright = ie - iroot;
        node->right = solve(postorder ,pe - iright , pe-1, inorder ,is+1 ,ie, imp);
        node->left = solve(postorder , ps , pe-iright-1 , inorder ,is , iroot-1 , imp);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        map<int , int> imp;
        for(int i=0;i<len;i++){
            imp[inorder[i]] = i;
        }
        return solve(postorder , 0 , len-1 , inorder , 0 , len-1 , imp);
    }
};