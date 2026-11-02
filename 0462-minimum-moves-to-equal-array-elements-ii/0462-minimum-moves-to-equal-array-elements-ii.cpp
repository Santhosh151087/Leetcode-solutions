class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int len = nums.size();
        int ans=0;
        int med = 0;
        sort(nums.begin() , nums.end());
        med = nums[len/2];
        
        for(int n:nums){
            ans+=abs(med-n);
        }
        return ans;

    }
};