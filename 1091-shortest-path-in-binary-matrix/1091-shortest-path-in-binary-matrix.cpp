class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        if(grid[0][0]==1 || grid[N-1][N-1]==1)
        return -1;
        priority_queue<tuple<int , int , int> ,
        vector<tuple<int , int,int>> ,
        greater<tuple<int , int , int>> > qu;
        qu.push({1 , 0 , 0});
       
        vector<int> dr = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
        vector<int> dc = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1};
        while(!qu.empty()){
            auto [cost , row , col ] = qu.top();
            qu.pop();
            if(row==N-1 && col==N-1)
            return cost;
            for(int i=0;i<8;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr>=0 && nc>=0 && nr<N && nc<N && grid[nr][nc]==0){
                    qu.push({cost+1 , nr , nc});
                    grid[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};