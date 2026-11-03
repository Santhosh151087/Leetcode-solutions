class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxx = INT_MIN;
        for(int n:nums){
            maxx = max(maxx , n);
        }
        int ans = 0;
        for(int n:nums){
            ans+=(maxx-n);
        }
        return ans;
    }
};