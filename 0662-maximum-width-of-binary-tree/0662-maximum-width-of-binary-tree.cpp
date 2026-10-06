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

 // THE MAIN CONCEPT IS ASSIGING INDEX FOR EACH NODE AND GET THE MAXwIDTH BY (RIGHT - LEFT +1) CURNODE IS i and left node will be i*2+1 and right will be i*2+2 if start i with 0 if start with 1 means i*2 and i*2+1 . but it leds to out of bounds so we just doing for each ndoe i = i-min;
 #define ll long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        queue<pair<TreeNode* , ll>> qu;
        qu.push({root ,0});
        while(!qu.empty()){
            int size = qu.size();
            ll minn = INT_MAX;
            for(int i=0;i<size;i++){
                pair<TreeNode* , ll> cur=qu.front();
                if(minn>cur.second)
                minn = cur.second;
                if(cur.first->left!=nullptr)
                qu.push({cur.first->left ,(cur.second-minn)*2+1 });
                if(cur.first->right!=nullptr)
                qu.push({cur.first->right ,(cur.second-minn)*2+2 });
                ans = max( ans , cur.second - minn+1);
                qu.pop();
            }
        }

        return ans;
    }
};