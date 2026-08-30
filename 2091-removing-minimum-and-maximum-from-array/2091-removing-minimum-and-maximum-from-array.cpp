class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxx = INT_MIN;
        int minn = INT_MAX;
        int minInd = 0;
        int maxInd = 0;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]<minn){
                minn = nums[i];
                minInd = i;
            }
            if(nums[i]>maxx){
                maxx = nums[i];
                maxInd = i;
            }
        }
        int lastInd = max(minInd , maxInd);
        int firstInd = min(minInd , maxInd);
        return min({lastInd+1 , len - firstInd , (firstInd+1) + (len - lastInd)});

    }
};