class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
         vector<pair<int , int>> arr;
         int ans = 0;
         for(vector<int> cur : intervals){
            arr.push_back({cur[0] , 1});
            arr.push_back({cur[1] , 2});
         }
         sort(arr.begin() , arr.end());
         int c = 0;
         for(pair<int , int> cur : arr){
            if(cur.second ==1)
            c+=1;
            else
            c-=1;
            ans = max(ans  ,c);
         }



         return ans;
    }
};