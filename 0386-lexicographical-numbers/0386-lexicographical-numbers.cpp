class Solution {
public:
    vector<int> ans;
    void solve(int cur  , int end){
        if(cur>end)
        return;
        ans.push_back(cur);
        for(int i=0;i<10;i++){
            if((cur * 10)+i >end)
            break;
            solve((cur * 10)+i , end);

        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<10;i++)
        solve(i , n);
        return ans;
    }
};