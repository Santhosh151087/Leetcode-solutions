class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int left = -k;
        int right = 0;
        deque<int> dq;
        while (right < nums.size()) {
            if(dq.empty() || nums[dq.back()] > nums[right]){
                dq.push_back(right);
            }
            else{
                while(!dq.empty() && nums[right]>nums[dq.back()]){
                      dq.pop_back();
                }
                dq.push_back(right);
            }
            while(!dq.empty() && left >=dq.front()){
                dq.pop_front();
            }
            if(!dq.empty() && right+1>=k ){
                ans.push_back(nums[dq.front()]);
            }
            right++;
            left++;
        }
        return ans;
    }
};