#define ll long long int
class Solution {
public:
    int GCD(int a , int b){
        if(a==0)
        return b;
        return GCD(b%a ,a);
    }
    int LCM(int a , int b){
        return (a*b) / (GCD(a , b));
    }
    int maxLength(vector<int>& nums) {
        int  ans = 1;
        for(int i=0;i<nums.size();i++){
            int lcm = nums[i];
            int gcd = nums[i];
            ll pro = nums[i];
            for(int j=i+1;j<nums.size();j++){
                
                pro = pro * nums[j];
                if(pro >INT_MAX)
                break;
                gcd = GCD(gcd , nums[j]);
                lcm = LCM(lcm , nums[j]);
                if(pro == gcd * lcm){
                    ans = max(ans , j-i+1);
                }
            }
        }
        return ans;
    }
};