class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(N);
         vector<int> in(N, 0);
        for(vector<int> cur:prerequisites){
            graph[cur[1]].push_back(cur[0]);
            in[cur[0]]++;
        }
        queue<int>qu;
       for(int i=0;i<N;i++){
        if(in[i]==0)
        qu.push(i);
       }
        vector<int> ans;
        while(!qu.empty()){
            int cur = qu.front();
            ans.push_back(cur);
            qu.pop();
            for(int adj : graph[cur]){
                in[adj]--;
                if(in[adj]==0)
                qu.push(adj);
            }
        }
    if(ans.size()!=N)
    return {};
        return ans;
    }
};