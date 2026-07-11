class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int left = 0;
        int right = 0;
        int len = nums.size();
        int ck =0;
        while(right<len){
            if(ck==k && nums[right]==0){
                while(nums[left]==1 && left<len)left++;
                left++;
            }
            else if(nums[right]==0)
            ck++;
            count = max(count , right - left+1);
            right++;
        }
        return count;
    }
};