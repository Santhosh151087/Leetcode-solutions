class Solution {
public:
    int solve(vector<int>& nums , int k){
        int ans = 0;
        int right = 0;
        int left = 0;
        map<int , int> mp;
        while(right < nums.size()){
            mp[nums[right]]++;
            while(mp.size()>k){
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                mp.erase(nums[left]);
                left++;
            }
            if(mp.size()<=k)
            ans+=(right-left+1);
            right ++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k-1);
    }
};