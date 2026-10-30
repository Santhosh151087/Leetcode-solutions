class Solution {
public:
    vector<bool> terminal;
    vector<bool> visited;
    bool DFS(vector<vector<int>>& graph , int cur ){
        if(terminal[cur])
        return true;
        if(visited[cur])
        return false;
        visited[cur] = true;
        for(int adj : graph[cur]){
            if(!DFS(graph , adj ))
            return false;
        }
        visited[cur] = false;
        return terminal[cur]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        int ind = 0;
        terminal.assign(N , false);
        visited.assign(N , false);
        for(vector<int> cur : graph){  
            if(cur.size()==0)
            terminal[ind] = true;
            ind++;
        }
        vector<int> ans;
        
        for(int i=0;i<N;i++){
            if(DFS(graph , i )){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};