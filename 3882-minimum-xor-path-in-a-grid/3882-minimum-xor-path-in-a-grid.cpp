class Solution {
public:
    int R , C;
    int ans = INT_MAX;
    vector<vector<vector<int>>> dp;
    // vector<int> cur;
    int DFS(vector<vector<int>>& grid , int r , int c , int XOR){
        if(r==R-1 && c==C-1){
            XOR^= grid[r][c];
           
            return XOR;
        }
        if(r<0 || c<0 || r==R || c==C )
        return INT_MAX;
        if(dp[r][c][XOR]!=-1)
        return dp[r][c][XOR];
        int prev = XOR;
        XOR^= grid[r][c];
        dp[r][c][prev] = DFS(grid , r+1 , c , XOR);
        dp[r][c][prev] = min( DFS(grid , r , c+1 , XOR) , dp[r][c][prev]);
        // XOR^= grid[r][c];
        return dp[r][c][prev];
    }
    int minCost(vector<vector<int>>& grid) {
        int sum = 0;
        R = grid.size();
        C = grid[0].size();
        
        dp.assign(R , vector<vector<int>>(C , vector<int>(1024,-1)));
        return DFS(grid , 0 , 0 , 0);
    //  return ans;
    }
};