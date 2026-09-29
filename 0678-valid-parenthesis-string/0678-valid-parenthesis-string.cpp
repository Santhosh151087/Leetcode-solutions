class Solution {
public:
    bool checkValidString(string s) {
        if(s[0]==')')
        return false;
        int start = 0;
        int stop = 0;
        for(char c : s){
            if(c=='('){
                start++;
                stop++;
            }
            else if(c==')'){
                start--;
                stop--;
            }
            else{ // in need to find the range where * is 
               start--;
               stop++;    
            }
            if(start<0)
            start =0;
            if(stop<0)
            return false;
        }
        return start==0;
    }
};