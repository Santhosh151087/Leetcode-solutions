// #define ll long long int
class Solution {
public:
     vector<vector<bool>> visited;
     int R , C;
     long long int DFS(vector<vector<int>> & grid , int r , int c){
        if(r<0 || c<0 || r==R || c==C || visited[r][c] || grid[r][c]==0)
        return 0;
        visited[r][c] = true;
        long long int ans = grid[r][c];
        ans+=DFS(grid , r+1 , c);
        ans+=DFS(grid , r-1 , c);
        ans+=DFS(grid , r , c+1);
        ans+=DFS(grid , r , c-1);
        return ans;
     }
    int countIslands(vector<vector<int>>& grid, int k) {
         R = grid.size();
         C = grid[0].size();
        int count = 0;
        visited.resize(R , vector<bool>(C, false));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!visited[i][j] && grid[i][j]!=0){
                    long long int dfs = DFS(grid ,i , j);
                    if(dfs%(long)k==0)
                    count++;
                }
            }
        }
        return count;
    }
};