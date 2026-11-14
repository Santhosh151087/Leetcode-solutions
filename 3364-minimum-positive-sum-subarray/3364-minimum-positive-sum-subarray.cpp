class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int len = nums.size();
        int sum = 0;
        for(int i=0;i<l-1;i++){
            sum+=nums[i];
        }
        // ans = min(ans , sum);
        for(int i=l-1;i<r;i++){
            sum+=nums[i];
           if(sum>0 && sum<ans)
           ans = sum;
            int cursum = sum;
            for(int j=i+1 , k=0;j<len;j++,k++){
                cursum-=nums[k];
                cursum+=nums[j];
                // ans = min(ans , cursum);
                if(cursum>0 && cursum<ans)
                ans = cursum;
            }
        }

        return ans ==INT_MAX ? -1 : ans;
    }
};