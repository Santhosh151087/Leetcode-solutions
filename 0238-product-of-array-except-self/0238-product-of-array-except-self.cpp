class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> pre(N , 1);
        vector<int> suf(N , 1);
        for(int i=1;i<N;i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        for(int i=N-2;i>=0;i--){
            suf[i] = suf[i+1] * nums[i+1];
        }
        vector<int> ans(N , 0);
        for(int i=0;i<N;i++){
            ans[i] = pre[i] * suf[i];
        }
        return ans;
    }
};