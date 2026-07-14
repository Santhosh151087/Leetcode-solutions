class Solution {
public:
    int solve(vector<int>& nums , int target , int ind){
        if(ind ==0){
            if(nums[0]==0 && target==0)
            return 2;
            if(target - nums[ind] ==0 || target+nums[ind]==0)
            return 1;
            return 0;
        }
        return solve(nums , target - nums[ind] , ind-1)+solve(nums , target + nums[ind] , ind-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , nums.size()-1);
    }
};