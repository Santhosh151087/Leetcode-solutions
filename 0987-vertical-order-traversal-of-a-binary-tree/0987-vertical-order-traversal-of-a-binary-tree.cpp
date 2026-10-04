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
 struct Group{
    public:
    TreeNode* Node ;
    int vertical ;
    int level;
    Group(TreeNode* _Node , int _vertical , int _level){
        this->Node = _Node;
        this->vertical = _vertical;
        this->level = _level;
    }
 };
class Solution {
public:
    
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int , map<int , multiset<int >>> mp;
        queue<Group> qu;
        qu.push(Group(root , 0 , 0));
        while(!qu.empty()){
            Group top  = qu.front();
            qu.pop();
            mp[top.vertical][top.level].insert(top.Node->val);
            if(top.Node->left!=nullptr){
                qu.push({top.Node->left , top.vertical-1 , top.level+1});
            }
            if(top.Node->right!=nullptr){
                qu.push({top.Node->right , top.vertical+1 , top.level+1});
            }
            
        }
        for(auto& [verticalmp , levelmp] : mp){
            vector<int> c;
            for(auto& [level , st] : levelmp){
                for(int val :st)
                c.push_back(val);
            }
            ans.push_back(c);
        }
        return ans;
    }
};