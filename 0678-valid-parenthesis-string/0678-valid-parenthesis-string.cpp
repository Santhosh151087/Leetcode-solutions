class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string s , int ind , int count){
        
        if(ind ==s.size() && count ==0)
        return true;
        if(ind ==s.size() && count!=0)
        return false;
        if(count <0)
        return false;
        if(dp[ind][count]!=-1)
        return dp[ind][count]==1;
        dp[ind][count] = 0;
        if(s[ind]=='('){
            if(solve(s , ind+1 , count+1)){
                dp[ind][count] = 1;
                return true;
            }
        }
         
        else if(s[ind]==')'){
            if(solve(s  , ind+1 , count-1)){
                dp[ind][count] = 1;
                return true;
            }
        }
         
        else{
            if(solve(s , ind+1 , count+1) || solve(s , ind+1 , count-1) || solve(s , ind+1 , count)){
                return true;
                dp[ind][count]=1;
            }
            
            
        }
        
        return false;
    }
    bool checkValidString(string s) {
        dp.resize(s.size()+1 ,vector<int> (s.size()+1 , -1));
        return solve(s ,0 , 0);
    }
};