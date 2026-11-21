class Solution {
public:
    vector<int> ans;
    vector<int> lastseen;
    vector<vector<int>> newchild; 
     vector<vector<int>> child;
     vector<int> parent;
    string s;
    int COUNT(vector<vector<int>> &child , int par){
        ans[par] = 1;
        for(int c : child[par]){
            ans[par]+=COUNT(child , c);
            
        }
        return ans[par];
    }
    void DFS(int node){
       int ch = s[node] -'a';
       int prev = lastseen[ch];
       if(prev!=-1){
        newchild[prev].push_back(node);
       }
       else if(node!=0){
         newchild[parent[node]].push_back(node);
       }
       lastseen[ch] = node;
       for(int c :child[node] ){
        DFS(c);
       }
       lastseen[ch] = prev;
    }
    vector<int> findSubtreeSizes(vector<int>& p, string str) {
        s = str;
        parent = p;
        int N = parent.size();
       child.resize(N);
        lastseen.assign(26 , -1);
        ans.assign(N ,-1);
        newchild.resize(N);
        for(int i=1;i<N;i++){
            child[parent[i]].push_back(i);
        }
        DFS(0);

       COUNT(newchild , 0);
        return ans;
    }
};