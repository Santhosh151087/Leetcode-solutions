class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        auto indd = lower_bound(nums.begin() , nums.end() , target);
        int ind =  indd-nums.begin();
        if(indd ==nums.end() || nums[ind]!=target)
        return {};
        // cout<<ind;
        vector<int> ans ; 
        while(ind < nums.size() && nums[ind]==target){
            ans.push_back(ind++);
        }
        
        return ans;
    }
};