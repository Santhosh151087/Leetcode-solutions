class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> out(N , 0);
        vector<vector<int>> revgraph(N);
        for(int i=0;i<N;i++){
            out[i] =graph[i].size();
            for(int cur : graph[i]){
                revgraph[cur].push_back(i);
            }
        }
        queue<int> qu;
        for(int i=0;i<N;i++){
            if(out[i]==0)
            qu.push(i);
        }
         vector<int> ans;
        while(!qu.empty()){
            int cur  = qu.front();
            qu.pop();
            ans.push_back(cur);
            for(int adj:revgraph[cur]){
                out[adj]--;
                if(out[adj]==0)
                qu.push(adj);
            }
        }
        
        sort(ans.begin() , ans.end());
        return ans;
    }
};