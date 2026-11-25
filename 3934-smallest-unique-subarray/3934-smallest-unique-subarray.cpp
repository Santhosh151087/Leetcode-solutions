class Solution {
public:
    #define ll long long int
    ll MOD1 = 1e9 + 7;
    ll BASE1 = 31;
    ll MOD2 = 1e9 + 9;
    ll BASE2 = 53;
    // ll MOD1
    bool solve(int size , vector<int>& nums){
        map<pair<ll , ll> ,int> mp;
        ll hash1 = 0;
        ll hash2 = 0;
        for(int i=0;i<size;i++){
            hash1 = (hash1* BASE1 + nums[i])%MOD1;
            hash2 = (hash2* BASE2 + nums[i])%MOD2;
        }
        mp[{hash1 , hash2}]++;
        ll high1 = 1;
        ll high2 = 1;
        for(int i=1;i<size;i++){
            high1 = (high1 * BASE1)%MOD1;
            high2 = (high2 * BASE2)%MOD2;
        }
       
        for(int i=0;i<nums.size()-size;i++){
            
            ll out = nums[i];
            ll in = nums[size+i];
            hash1  = (((hash1 - high1* out)%MOD1)+MOD1)%MOD1;
            hash2  = (((hash2 - high2* out)%MOD2)+MOD2)%MOD2;
            hash1 = (hash1 * BASE1 + in)%MOD1;
            hash2 = (hash2 * BASE2 + in)%MOD2;
            mp[{hash1 , hash2}]++;
        }
        for(auto [key , freq]:mp){
            if(freq==1)
            return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int low = 1;
        int high1 = nums.size();
        int ans = nums.size();
        while(low<=high1){
             int mid = (low+high1)/2;
            if(solve(mid , nums)){
                ans = mid;
                high1 = mid -1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
};