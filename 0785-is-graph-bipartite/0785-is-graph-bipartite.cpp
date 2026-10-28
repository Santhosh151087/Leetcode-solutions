class Solution {
public:
    vector<int> color;
    bool DFS(vector<vector<int>>& graph , int node , int col){
        
        color[node] = col;
        for(int adj : graph[node]){
            if(color[adj]==col)
            return false;
            if(color[adj]==-1){
                if(!DFS(graph , adj ,col==0?1:0 ))
                return false;
            }
           
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int N = graph.size();
        color.assign(N , -1);
        for(int i=0;i<N;i++){
            if(color[i]==-1 && !DFS(graph , i ,0 ))
            return false;
        }
        return true;
    }
};