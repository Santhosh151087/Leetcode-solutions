class Solution {
public:
    #define ll long long int
 
    ll cat(ll n){
       if(n<=1)
       return 1;
       ll res = 0;
       for(int i=0;i<n;i++){
        res+=(cat(i) * cat(n-i-1));
       }
       return res;
    }
    int numTrees(int n) {
        return (int)cat(n);
    }
};