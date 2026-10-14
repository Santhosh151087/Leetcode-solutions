class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9 < sum)
        return "";
        string ans = "";
        while(num-->0){
            int cur = min(9 , sum);
            sum-=cur;
            ans+=to_string(cur);
        }
        return sum==0?ans:"";
    }
};