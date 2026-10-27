class Solution {
public:
    vector<bool> visited;
    vector<bool> path;
    bool DFS(vector<vector<int>> & adj , int cur ){
        if(path[cur])
        return true;
        if(visited[cur])
        return false;
        visited[cur] = true;
        path[cur] = true;
        for(int ad : adj[cur]){
            if(DFS(adj ,ad ))
            return true;
        }
        path[cur] = false;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)
        return true;
        visited.resize(N , false);
        path.resize(N , false);
        vector<vector<int>> adjacent(N , vector<int>());
        for(vector<int> cur :prerequisites ){
            // adjacent[cur[0]].push_back(cur[1]);
            adjacent[cur[1]].push_back(cur[0]);
        }
        for(int i=0;i<N;i++){
            
            if(!visited[i] && DFS(adjacent , i ))
            return false;
        }
        return true;
    }
};