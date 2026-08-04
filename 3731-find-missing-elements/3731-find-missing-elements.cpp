class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minn = nums[0];
        int maxx = nums[0];
        set<int> st;
        int len = nums.size();
        for(int i=0;i<len;i++){
            minn = min(minn , nums[i]);
            maxx = max(maxx , nums[i]);
            st.insert(nums[i]);
        }
        vector<int> ans;
        for(int i=minn+1;i<maxx;i++){
            if(st.find(i)==st.end())
            ans.push_back(i);
        }
        return ans;
    }
};