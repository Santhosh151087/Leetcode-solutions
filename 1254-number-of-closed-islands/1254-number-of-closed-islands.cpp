class Solution {
public:
 queue<tuple<int , int>> qu;
 int N, M;
 vector<vector<bool>> visited;
 vector<int> dr = {-1 , 1 , 0 , 0};
 vector<int> dc = {0 ,0 ,-1 , 1};
 int count = 0;
    void bfs(vector<vector<int>>& grid){
     while(!qu.empty()){
      
            auto [r , c] = qu.front();
            qu.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<N && nc<M && !visited[nr][nc] && grid[nr][nc]==0){
                    visited[nr][nc] = true;
                    qu.push({nr , nc});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
         N = grid.size();
         M = grid[0].size();
       visited.resize(N , vector<bool>(M , false));
       
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if((i==0 || j==0 || i==N-1 || j==M-1 ) && !visited[i][j] && grid[i][j]==0){
                    visited[i][j] = true;
                    qu.push({i , j});
                    
                }
            }
        }
       bfs(grid);
          count = 0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    count++;
                    visited[i][j] = true;
                    qu.push({i , j});
                    bfs(grid);
                }
            }
        }
       
      
        return count;
    }
};