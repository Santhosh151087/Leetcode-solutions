class Solution {
public:
    vector<int> psee(vector<int> & arr){
        vector<int> ans(arr.size());
        stack<pair<int , int>> st ;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top().second;
            }
            st.push({arr[i] , i});
        }
        return ans;
    }
     vector<int> nsee(vector<int> & arr){
         vector<int> ans(arr.size());
        stack<pair<int , int>> st ;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = arr.size();
            }
            else{
                ans[i] = st.top().second;
            }
            st.push({arr[i] , i});
        }
        return ans;
    }
    // void print(vector<int> & arr){
    //     for(int n:arr)cout<<n<<" ";
    //     cout<<endl;
    // }
    int MOD = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = psee(arr);
        vector<int> nse = nsee(arr);
        // print(pse);
        // print(nse);
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            int left = 1;
            int right = 1;
            
                left = i- pse[i];
            
           
                right = nse[i] - i;
            // cout<<left*right<<endl;
            ans = (ans +((1ll * left * right * arr[i])%MOD))%MOD;
        }
        return (int)ans;

    }
};