class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int  ,int , int>> qu;
        int N = grid.size();
        int M = grid[0].size();
        int ans = 0;
        int step = 1;
        int onecount = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==2){
                    grid[i][j] = 0;
                    qu.push({i , j , 0});
                }
                if(grid[i][j]==1)
                onecount++;
            }
        }
        if(onecount==0)
        return 0;
        vector<int> dr = {-1 , 1 , 0 , 0};
        vector<int> dc = {0 , 0 , -1 , 1};
        while(!qu.empty()){
           auto [r , c , s] = qu.front();
           qu.pop();
           if(s==step){
            ans++;
            step++;
           }
            for(int i=0;i<4;i++){
                int nr = r +dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr < N && nc<M && grid[nr][nc]==1){
                    grid[nr][nc] = 0;
                    qu.push({nr , nc , s+1});
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                
                if(grid[i][j]==1)
                return -1;
            }
        }
        return ans;
    }
};