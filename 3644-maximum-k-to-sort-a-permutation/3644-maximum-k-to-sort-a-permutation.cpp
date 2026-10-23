class Solution {
public:
    int sortPermutation(vector<int>& arr) {
       int ans = -1;
       // hint -1 with anynumber give that number
       for(int i=0;i<arr.size();i++){
        if(i!=arr[i])
        ans&=arr[i];
        if(ans==0)
        return 0;
       }
       return max(0 , ans);

    }
};