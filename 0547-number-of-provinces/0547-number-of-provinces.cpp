class Solution {
public:
    vector<int> leader;
    int find(int node){
        if(node !=leader[node])
            leader[node] = find(leader[node]);
        return leader[node];
    }
    void join(int left , int right){
        leader[find(right)] = find(left);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
         leader.resize(N+1 );
        for(int i=1;i<=N;i++){
            leader[i] = i;
        }
        for(int row =0;row<N;row++){
            for(int col =0;col<N;col++){
                if(isConnected[row][col]==1){
                    join(row+1 ,col+1);
                }
            }
        }
        set<int> s;
        for(int i=1;i<=N;i++){
            s.insert(find(leader[i]));
        }
        return s.size();
    }
};