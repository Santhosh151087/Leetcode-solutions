class Solution {
public:
    vector<string> ans;
    void solve(string s, int n, int open, int close) {
        if (s.size() == n * 2) {
            ans.push_back(s);
            return;
        }
        if (open < n)
            solve(s + '(', n, open + 1, close);
        if (close < open)
            solve(s + ')', n, open, close + 1);
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, 0, 0);
        return ans;
    }   
};  