class Solution {
public:
    vector<bool> visited;
    vector<bool> path;
    bool DFS(vector<vector<int>>& graph , int cur){
        if(path[cur])
        return false;
        if(visited[cur])
        return true;
        visited[cur] = true;
        path[cur] = true;
        for(int adj : graph[cur]){
            if(!DFS(graph ,adj))
            return false;

        }
        path[cur] = false;
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        visited.assign(N , false);
        path.assign(N , false);
        for(int i=0;i<N;i++){
            if(!visited[i])
            DFS(graph , i);
        }
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(!path[i])
            ans.push_back(i);
        }
        return ans;
    }
};