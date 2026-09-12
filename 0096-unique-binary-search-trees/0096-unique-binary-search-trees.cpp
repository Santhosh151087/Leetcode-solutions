class Solution {
public:
    #define ll long long int
    vector<int> dp;
    ll cat(ll n){
       if(n<=1)
       return 1;
       if(dp[n]!=-1)
       return dp[n];
       ll res = 0;
       for(int i=0;i<n;i++){
        res+=(cat(i) * cat(n-i-1));
       }
       return dp[n]=res;
    }
    int numTrees(int n) {
        dp.resize(n+1 , -1);
        return (int)cat(n);
    }
};