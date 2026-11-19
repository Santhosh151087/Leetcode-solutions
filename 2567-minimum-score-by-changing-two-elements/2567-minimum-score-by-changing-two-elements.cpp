class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int maxx = INT_MIN;
        int min1 = INT_MAX; 
        int min2 = INT_MAX; 
        int min3 = INT_MAX; 
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        for(int n: nums){
           
            if(min1 > n){
                min3 = min2;
                min2 = min1;
                min1 = n;
            }
            else if(min2 > n){
                min3 = min2;
                min2 = n;
            }
            else if(min3 > n){
                min3 = n;
            }
            if(max1 < n){
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if(max2 < n){
                max3 = max2;
                max2 = n;
            }
            else if(max3 <n){
                max3 = n;
            }

        }
        
        return min({max1 - min3 , max3 - min1 , max2 - min2});
    }
};