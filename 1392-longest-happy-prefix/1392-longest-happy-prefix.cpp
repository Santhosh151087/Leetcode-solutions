class Solution {
public:
    vector<int> LPS(string s){
        int N = s.size();
        int len = 0;
        int i = 1;
        vector<int> lps(N , 0);
        while(i<N){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len==0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int> lps = LPS(s);
        int maxlen =lps[s.size()-1] ;
        int ind = s.size()-1;
        
        // cout<<maxlen;
        if(maxlen==0)
        return "";
        return s.substr(0 , maxlen);

    }
};