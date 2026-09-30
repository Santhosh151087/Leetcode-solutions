class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int N = nums.size();
        int left = 0;
        int right = 0;
        while(right < N-1){
            int maxjump = 0;
           for(int i=left;i<=right;i++){
            maxjump = max(maxjump , i+nums[i]);
           } 
           jumps++;
            left = right+1;
            right = maxjump;
        }

        return jumps;
    }
};