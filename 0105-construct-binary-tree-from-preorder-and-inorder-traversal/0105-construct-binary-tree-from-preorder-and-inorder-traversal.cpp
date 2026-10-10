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
    TreeNode* solve(vector<int>& preorder , int ps , int pe , vector<int>& inorder , int is ,int ie , map<int , int>& imp){
        if(ps>pe || is >ie)
        return nullptr;
        TreeNode* node = new TreeNode(preorder[ps]);
        int iroot = imp[preorder[ps]];
        int ileft = iroot - is;
        node->left =solve(preorder , ps+1 ,ps+ileft , inorder , is , is+ileft, imp ) ;
        node->right = solve(preorder , ps+ileft+1 , pe , inorder , iroot+1 , ie , imp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        map<int , int> imp;
        for(int i=0;i<len;i++)imp[inorder[i]] = i;

        return solve(preorder ,0 , len-1, inorder , 0 , len-1 , imp);
    }
};