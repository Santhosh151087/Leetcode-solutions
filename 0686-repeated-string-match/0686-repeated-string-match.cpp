class Solution {
public:
    #define ll long long int 
    ll MOD = 1e9 + 7;
    ll BASE = 31;
    vector<ll> pow;
    bool find(string &txt , string &target , ll hash){
        int N = txt.size();
        int M = target.size();
        if(N<M)
        return false;
        ll curhash = 0;
        for(int i=0;i<M;i++){
            curhash = (curhash+(pow[M-i-1] * (txt[i] - 'a'+1)))%MOD;
        }
        for(int i=0;i<=N-M;i++){
            if(hash ==curhash){
                if(target == txt.substr(i , M))
                return true;
            }
            
            if(i<N-M){
                ll in = txt[i+M] - 'a' +1;
                ll out = txt[i] - 'a' +1;
                curhash = ((((curhash - out* pow[M-1])%MOD)+MOD)%MOD);
                curhash = (curhash * BASE + in)%MOD;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int N = a.size();
        int M = b.size();
        int k = (M+N-1)/N;
        ll hash = 0;
        pow.assign(M , 1);
        for(int i=1;i<M;i++){
            pow[i] = (pow[i-1] * BASE)%MOD; 
        }
        for(int i=0;i<M;i++){
            ll cur = b[i] - 'a' +1;
            hash = (hash + (pow[M-i-1] * cur) )%MOD;
        }
        // cout<<hash;
        string cur = "";
        for(int i=1;i<=k+1;i++){
            cur+=a;
            if(find(cur ,b , hash))
            return i;
        }
        return -1;

    }
};