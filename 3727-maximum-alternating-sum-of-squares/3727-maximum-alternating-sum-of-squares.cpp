#define ll long long int 
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        int len = nums.size();
        for(int i=0;i<len;i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin() , nums.end());
        ll left = 0;
        ll right = 0;
        for(int i=0;i<len;i++){
            if(i<len/2){
                left+=(1LL*nums[i]*nums[i]);
            }
            else
            right+=(1LL *nums[i]*nums[i]);
        }
        
        return right - left;
    }
};