class Solution {
public:
    int minChanges(string s) {
        int len = s.size();
        int count = 0;
        for(int i=0;i<len;i+=2){
            if(s[i]!=s[i+1])
            count++;
        }
        return count;
    }
};