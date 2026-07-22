class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int , int> m;
         sort(nums.begin() , nums.end());
        for(int i=0;i<nums.size();i++){
            m[nums[i]] = i;
        }
       
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])
                continue;
                int sum =-(nums[i]+nums[j]);
                if(m.find(sum)!=m.end() && m[sum]>i && m[sum]>j){
                    ans.push_back({nums[i] , nums[j] , sum});
                    // cout<<i<<" "<<j<<" "<<m[sum]<<endl;
                }
                

            }
        }
        return ans;
     }
};