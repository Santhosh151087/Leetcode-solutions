class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int N = heights.size();
       int  M = heights[0].size();
        
    vector<int> dr = {1 , - 1, 0 , 0};
    vector<int> dc = {0 , 0 , -1 , 1};
    vector<vector<int>> ans(N , vector<int>(M , INT_MAX));
    priority_queue<tuple<int , int , int>,
    vector<tuple<int , int  ,int>>,
    greater<tuple<int , int , int>>> qu;
    ans[0][0] = 0;
    qu.push({0 , 0 , 0});
    while(!qu.empty()){
        auto [prevdis , r , c] = qu.top();
        qu.pop();
        if(r==N-1 && c==M-1)
        return prevdis;
        if (prevdis > ans[r][c]) continue;

         for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nc>=0 && nr<N && nc<M){
            
               int curdis = abs(heights[r][c] - heights[nr][nc]);
               int maxdis = max(curdis , prevdis);
               if(maxdis< ans[nr][nc]){
                ans[nr][nc] = maxdis;
                qu.push({maxdis , nr , nc});
               }
            }
        }
    }
    
return ans[N-1][M-1];
    }
};