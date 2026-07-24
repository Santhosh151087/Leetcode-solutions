class Solution {
public:
    int find(vector<int>& nums, int goal){
        if(goal<0)
        return 0;
         int ans = 0;
        int right = 0;
        int left = 0;
        int sum = 0;
        while(right<nums.size()){
            sum +=nums[right];
           
            while(sum>goal){
               sum-=nums[left++];
            }
            ans+=(right-left)+1;
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return find(nums, goal) - find(nums , goal-1);
    }
};