#define ll long long int
class Solution {
public:
    long long countCommas(long long n) {
        
        if(n<1000)
        return 0;
        ll ans = 0;
        for(ll i=999;i<=n;i=(i*1000)+999){
            ans +=(n-i);
        }
       return ans;
    }
};