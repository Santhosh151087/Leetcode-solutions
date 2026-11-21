class Solution {
public:
    int LPS(string s){
        int len = s.size();
        vector<int> lps(len , 0);
        int i = 1;
        int j = 0;
        while(i<len){
        if(s[i]==s[j]){
            j++;
            lps[i] = j;
            i++;
            
        }
        else{
            if(j!=0){  
                j = lps[j-1];
            }
            else{
                 lps[i] = 0;i++;
            }
           
        }
        }
        return lps[len-1];
    }
    bool repeatedSubstringPattern(string s) {
      int len = LPS(s); 
      
       return len>0 && s.size()%(s.size()-len)==0;
    }
};