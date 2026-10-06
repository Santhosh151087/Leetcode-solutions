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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = qu.front();
                qu.pop();
                if (cur->left != nullptr) {
                    qu.push(cur->left);
                    parent[cur->left] = cur;
                }
                if(cur->right!=nullptr){
                    qu.push(cur->right);
                    parent[cur->right] = cur;
                }
            }
        }
        // cout<<parent.size();
        // for(auto &[key , val] : parent)
        // cout<<key<<" "<<val<<endl;
        parent[root] = root;
        queue<pair<TreeNode* , int>> q ;// Node , dis
        vector<int> ans;
        q.push({target , 0});
        set<TreeNode*> visited;
        while(!q.empty()){
            pair<TreeNode* , int> cur=q.front();
            q.pop();
            if(visited.find(cur.first)!=visited.end())
            continue;
            visited.insert(cur.first);
            if(cur.second==k){
                ans.push_back(cur.first->val);
                continue;
            } 
            if(cur.first->left!=nullptr){
                q.push({cur.first->left , cur.second+1});
            }
            if(cur.first->right!=nullptr){
                q.push({cur.first->right , cur.second+1});
            }
            q.push({parent[cur.first] , cur.second+1});
            

            

        }
        return ans;
    }
};