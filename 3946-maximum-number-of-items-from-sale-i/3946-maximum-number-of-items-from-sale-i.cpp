class Solution {
public:
    vector<int> factor;
    int min_price = INT_MAX;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& items, int budget , int ind){
        
        if( ind==items.size() )
        return budget/min_price;
        if(dp[ind][budget]!=-1)
        return dp[ind][budget];
        int nonpick = solve(items , budget  , ind+1); 
        int pick = 0;
        if(budget>=items[ind][1]){
           pick = 1 + factor[ind] + solve(items, budget - items[ind][1], ind + 1);
        } 
       return dp[ind][budget]=max(pick , nonpick);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int N = items.size();
        dp.resize(N+1 , vector<int>(budget+2  , -1));
        factor.resize(N,0);
        for(int i=0;i<N;i++){
            min_price = min(min_price , items[i][1]);
            for(int j=0;j<N;j++){

                if(i!=j && items[j][0]%items[i][0]==0)
                factor[i]++;
            }
        }
        return solve(items , budget , 0);
        // return 0;
    }
};