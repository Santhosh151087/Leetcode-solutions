class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> qu;
        int N = board.size();
        int M = board[0].size();
        vector<vector<bool>> visited(N , vector<bool> (M , false));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if((i==0 || j==0 || i==N-1 || j==M-1) && board[i][j] == 'O'){
                    qu.push({i , j});
                    visited[i][j] = true;
                }
            }
        }
        vector<int> dr = {-1 , 1 , 0 ,0};
        vector<int> dc = {0 ,0 , -1 , 1};
        while(!qu.empty()){
            auto cur = qu.front();
            qu.pop();
            int r = cur.first;
            int c = cur.second;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<N && nc<M && !visited[nr][nc]&& board[nr][nc]=='O'){
                    visited[nr][nc] = true;
                    qu.push({nr , nc});
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visited[i][j])
                board[i][j] = 'X';
            }
        }
    }
};

