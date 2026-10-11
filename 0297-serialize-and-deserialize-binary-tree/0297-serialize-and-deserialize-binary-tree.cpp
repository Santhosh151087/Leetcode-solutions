    /**
    * Definition for a binary tree node.
    * struct TreeNode {
    *     int val;
    *     TreeNode *left;
    *     TreeNode *right;
    *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    * };
    */
    class Codec {
    public:

        // Encodes a tree to a single string.
        void solve(TreeNode* root , string& s){
            if(root==nullptr){
                s+=",null";
                return;
            }
            int cur = root->val;
            s+=","+to_string(cur);
            solve(root->left , s);
            solve(root->right , s);
            
        }
        string serialize(TreeNode* root) {
            string ans = "";
            solve(root , ans);
        return ans.substr(1);
        }
        TreeNode* solve(stringstream & ss){
            string cur;
            if(!getline(ss , cur ,',') || cur=="null")
            return nullptr;
            TreeNode* root = new TreeNode(stoi(cur));
            root->left = solve(ss);
            root->right = solve(ss);
            return root;
        }
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
        queue<TreeNode*> qu;
        if(data.empty())
        return nullptr;
         stringstream ss(data);
        return solve(ss);
        
        }
    };

    // Your Codec object will be instantiated and called as such:
    // Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));