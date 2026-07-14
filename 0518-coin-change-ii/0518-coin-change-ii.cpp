class Solution {
public:
    // vector<int> list;
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int amount, int index) {
        if (amount == 0) {

            return 1;
        }

        if (amount < 0)
            return 0;
        if(dp[amount][index]!=-1)
        return dp[amount][index];
        int count = 0;
        for (int i = index; i < coins.size(); i++) {
            if (amount >= coins[i]) {
                // list.push_back(coins[i]);
                count += solve(coins, amount - coins[i], i);
                // list.pop_back();

            }

            else
                break;
        }
        return dp[amount][index]=count;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        dp.resize(amount+1 ,vector<int>(coins.size()+1 , -1));
        return solve(coins, amount, 0);
    }
};