class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<long> dp(n);
        dp[0] = 0;
        for(int i=0;i<n-1;i++){
            dp[i+1] = dp[i] + (nums[i+1] - nums[i]<=maxDiff ? 1:-1);
            // cout<<dp[i+1]<<" ";
        }
        // cout<<endl;

        for(int ind=0;ind<queries.size();ind++){
            int start = queries[ind][0];
            int end = queries[ind][1];
            if(start>end){
                int temp = start;
                start = end;
                end = temp;
            }
            // cout<<start<<" "<<end<<" "<<dp[start]<<" "<<dp[end]<<" "<<endl;
            if(dp[end] - dp[start] == end-start)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};