class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int N = nums.size();
        vector<int> pre(N+1 , 0);
        vector<int> suf(N+1 , 0);
        for(int i=0;i<N;i++){
            pre[i+1] = pre[i] + nums[i];
        }
        for(int i=N-1;i>=0;i--){
            suf[i] = suf[i+1]+ nums[i];
        }
        vector<int> ans(N);
        for(int i=0;i<N;i++){
            int back = suf[i] - (nums[i]* (N - i));
            int front = (nums[i]* (i+1))-pre[i+1];
            ans[i] =front+back ;
        }
        return ans;
    }
};