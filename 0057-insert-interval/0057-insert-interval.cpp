class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int ind = 0;
        vector<vector<int>> ans;
        int N = intervals.size();
        while (ind < N && intervals[ind][1] < newInterval[0]) {
            ans.push_back({intervals[ind][0], intervals[ind][1]});
            ind++;
        }
        while (ind < N && intervals[ind][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0],intervals[ind][0] );
            newInterval[1] = max(newInterval[1] , intervals[ind][1]);
            ind++;
        }
        ans.push_back({newInterval[0] , newInterval[1]});
        while (ind < N) {
            ans.push_back({intervals[ind][0], intervals[ind][1]});
        ind++;
        }

        return ans;
    }
};