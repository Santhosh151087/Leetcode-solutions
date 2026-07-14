class Solution {
public:
int sum = 0;
    vector<vector<int>> dp;
    int solve(vector<int>& nums , int target , int ind){
         if (target + sum < 0 || target + sum > 2 * sum) return 0;
        if(ind ==0){
            if(nums[0]==0 && target==0)
            return 2;
            if(target - nums[ind] ==0 || target+nums[ind]==0)
            return 1;
            return 0;
        }
        if(dp[ind][target+sum]!=-1)
        return dp[ind][target+sum];
        return dp[ind][target+sum]=solve(nums , target - nums[ind] , ind-1 )+solve(nums , target + nums[ind] , ind-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        for(int n:nums)sum+=n;
        if(abs(target)>sum)
        return 0;
        dp.resize(nums.size()+1 , vector<int>(target+(sum*2)+1 , -1));
        return solve(nums , target , nums.size()-1);
    }
};