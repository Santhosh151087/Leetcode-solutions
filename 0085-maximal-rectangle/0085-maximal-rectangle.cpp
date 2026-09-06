class Solution {
public:
    int solve(vector<int> arr){
        stack<pair<int , int >> st;
        int len = arr.size();
        int ans = -1;
        for(int i=0;i<len;i++){
            
            if(st.empty() || st.top().first<arr[i]){
                st.push({arr[i] , i});
            }
            else{
                
                while(!st.empty() && st.top().first > arr[i]){
                    pair<int , int> tp = st.top();
                    st.pop();
                    int next = i ;
                    int prev = st.empty() ? -1 : st.top().second;
                    ans = max(ans , (next-prev-1)*tp.first); 
                }
               
                st.push({arr[i] , i});
            }
        }
        while(!st.empty()){
           
           pair<int , int> tp = st.top();
            st.pop();
            int next = len ;
            int prev = st.empty() ? -1 : st.top().second;
            ans = max(ans , (next-prev-1)*tp.first); 
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int len = matrix[0].size();
        vector<int> dp (len , 0);
        int ans =0;
        for(int i=0;i<matrix.size();i++){
            vector<int> ndp(len , 0);
            for(int j=0;j<matrix[0].size() ; j++){
                if(matrix[i][j] =='1'){
                    ndp[j] = dp[j] +1;
                }
            }
            dp = ndp;
            ans = max(ans , solve(dp));
        }
        return ans;
    }
};