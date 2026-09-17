class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans(arr.size());
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int n:arr){
            pq.push(n);
        }
        map<int , int> mp;
        int ind = 1;
        while(!pq.empty()){
            if(mp.find(pq.top())==mp.end()){
                mp[pq.top()] = ind;
                 ind++;
            }
            pq.pop();
           
        }
        for(int i=0;i<arr.size();i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};