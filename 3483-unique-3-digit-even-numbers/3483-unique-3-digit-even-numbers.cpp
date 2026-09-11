class Solution {
public:
    vector<int> ans;
    set<vector<int>> st ;
    void solve(vector<int>& arr, int ind) {
        if(ans[0]!=-1 && ans[1]!=-1 && ans[2]!=-1){
            // cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
            if(ans[2]%2==0)
            st.insert(ans);
            return;
        }
        if(ind ==-1)
        return;
        if(ans[0]==-1){
            if(arr[ind]!=0){
                int  temp = ans[0];
                ans[0] = arr[ind];
                solve(arr , ind-1);
                ans[0] = temp; 
            }
        }
         if(ans[1]==-1){
            if(arr[ind]!=ans[0]){
                int temp = ans[1];
                ans[1] = arr[ind];
                solve(arr , ind-1);
                ans[1] = temp;
            }
        }
         if(ans[2]==-1){
            if(arr[ind]!=ans[0] && arr[ind]!=ans[1]){

                int temp = ans[2];
                ans[2] = arr[ind]; 
                solve(arr , ind-1);
                ans[2] = temp;
            }
        }
        solve(arr , ind-1);
    }
    int totalNumbers(vector<int>& digits) {
        ans.resize(3  , -1);
         solve(digits, digits.size() - 1);
         return st.size();
    }
};
