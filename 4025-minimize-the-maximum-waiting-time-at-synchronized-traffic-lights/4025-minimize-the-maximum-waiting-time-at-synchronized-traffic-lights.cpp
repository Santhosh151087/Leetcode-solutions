class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ans = 0;
        int maxx = INT_MIN;
        for(int n : lights)
        maxx = max(maxx , n);
        for(int cur : arrivalTime){
            int r = cur % period; 
            if(r>= maxx){
                ans = max(ans ,  period - r);
            }
        }
        return ans;
    }
};