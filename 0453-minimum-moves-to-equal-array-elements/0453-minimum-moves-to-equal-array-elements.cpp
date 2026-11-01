class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minn = INT_MAX;
        for(int n:nums)
        minn = min(minn , n);
        int ans = 0;
        for(int n:nums){
            ans+=( n - minn);
        }
        return ans;
    }
};