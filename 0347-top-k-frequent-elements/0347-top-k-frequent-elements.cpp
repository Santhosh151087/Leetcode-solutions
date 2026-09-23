class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> freq;
        for(int n : nums){
            freq[n]++;
        }
        priority_queue<pair<int , int>> pq;
        for(auto& [key , val] : freq){
            pq.push({val , key});
        }
        vector<int> ans;
        while(k-- >0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};