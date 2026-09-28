class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // int ans = 0;
        vector<pair<int ,int>> arr;
        for(vector<int> cur : intervals){
            arr.push_back({cur[1] , cur[0]});
        }
        sort(arr.begin() , arr.end());
        int ans = 0;
        int prev = INT_MIN;
        for(pair<int , int> cur : arr){
            if(prev<=cur.second){
                prev = cur.first;
                ans++;
            }
        }
        return intervals.size() - ans;
    }
};