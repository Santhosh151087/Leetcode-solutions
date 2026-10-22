class Solution {
public:
    int minOperations(vector<int>& nums) {
        int as = 1;
        int ds = 1;
        int N = nums.size();
        for(int i=1;i<N;i++){
            if(nums[i]==(nums[i-1]+1)%N)
            as++;
            if((nums[i]+1)%N==(nums[i-1]))
            ds++;
        }
        if(as==N ){
            if(nums[0]==0)
            return 0;
            return min(N-nums[0] , nums[0]+2);
        }
        if(ds==N){
            return min(nums[N-1] , N - nums[N-1])+1;
        }
        return -1;
    }
};