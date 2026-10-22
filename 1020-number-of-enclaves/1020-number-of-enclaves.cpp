class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int , int>> qu;
        int N = grid.size();
        int M = grid[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                // cout<<grid[i][j]<<" ";
                if((i==0 || j==0 || i==N-1 || j==M-1) && grid[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    qu.push({i , j});
                    grid[i][j] = 0;
                }
            }
            // cout<<endl;
        }
        cout<<endl;
        vector<int> dr = {-1 , 1 , 0 , 0};
        vector<int> dc = {0 ,  0 , 1 , -1};
        while(!qu.empty()){
            auto cur = qu.front();
            qu.pop();
            int r = cur.first;
            int c = cur.second;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<N && nc<M && grid[nr][nc]==1){
                    grid[nr][nc] = 0;
                    qu.push({nr , nc});
                }
            }
            
        }
        int count = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1){
                    count++;
                }
            }
            // cout<<endl;
        }
        return count;
    }
};