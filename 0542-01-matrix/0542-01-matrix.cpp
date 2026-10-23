class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int N = mat.size();
        int M = mat[0].size();
        vector<vector<int>> ans(N , vector<int>(M ,0));
        vector<vector<bool>> visited(N , vector<bool>(M , false));
        queue<tuple<int , int , int>> qu;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(mat[i][j]==0){
                    qu.push({i , j , 0});
                    visited[i][j] = true;
                }
            }
        }
        vector<int> dr = {-1 , 1 , 0 ,0};
        vector<int> dc = {0 , 0 , -1 , 1};
        while(!qu.empty()){
            auto [r , c , step] = qu.front();
            qu.pop();
            ans[r][c] = step;
            
           for(int i=0;i<4;i++){
            int nr  = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<N && nc<M && !visited[nr][nc]){
                visited[nr][nc] = true;
                qu.push({nr , nc , step+1});
            }
           }
        }
        return ans;
    }
};