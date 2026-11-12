class Solution {
public:
    #define ll long long int
        int deleteString(string s) {
        ll MOD1 = 1000000007;
        ll MOD2 = 1000000009;
        ll BASE = 31;
        int N = s.size();
        vector<ll> h1(N+1);
        vector<ll> h2(N+1);
        vector<ll> p1(N+1);
        vector<ll> p2(N+1);
        h1[0] = 0;
        h2[0] = 0;
        p1[0] = 1;
        p2[0] = 1;
        for(int i=0;i<N;i++){
            ll val = (s[i]-'a') +1;
            h1[i+1] = (h1[i] * (BASE) +val )%MOD1;
            h2[i+1] = (h2[i] * (BASE) + val)%MOD2;
            p1[i+1] = (BASE * p1[i])%MOD1;
            p2[i+1] = (BASE * p2[i])%MOD2;
        }
        vector<ll> dp(N+1);
        for(int i=N-1;i>=0;i--){
            dp[i] =1 ;
           for(int len=1;i+2*len<=N;len++){
            // sub[l,r) = h1[r] - h1[l] + base^ r-l
            ll a1 =( ((h1[i+len] - h1[i] * p1[len])%MOD1)+MOD1)%MOD1;
            ll a2 =( ((h2[i+len] - h2[i] * p2[len])%MOD2)+MOD2)%MOD2;

            ll b1 = (((h1[i+len*2] - h1[i+len] * p1[len])%MOD1)+MOD1)%MOD1;
            ll b2 = (((h2[i+len*2] - h2[i+len] * p2[len])%MOD2)+MOD2)%MOD2;
            if(a1==b1 && a2==b2){
                dp[i] = max(dp[i] , 1+dp[i+len]);
            }
           } 
        }
        return dp[0];
    }
};