class Solution {
public:
    vector<string> ans;
    vector<string> cur;
    bool solve(int M , int N ,int r , int c){
        if(M-1==r && N-1==c){
            cur[r][c] = '.';
            ans = cur;
            return true;
        }
        if(M==r || c==N)
        return false;
    cur[r][c] = '.';
    bool ippo = solve(M , N , r+1 , c) || solve(M , N , r , c+1);
    
    cur[r][c] = '#';
    return ippo;
    }
    vector<string> createGrid(int m, int n) {
        cur.resize(m);
        for(string &c: cur)
        c.resize( n , '#');
        solve(m , n , 0 , 0);
        return ans;
    }
};