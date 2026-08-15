class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            int cur = arr[i];
            if(st.empty() || (st.top()<0 && cur <0 ) || (st.top()<0  && cur<0))
            st.push(cur);
            else if(cur > 0){
                int curabs = abs(cur);
                while(!st.empty() && st.top()<0 && abs(st.top()) < curabs){
                    st.pop();
                }
                if(!st.empty() && st.top()<0 && abs(st.top()) == curabs)
                st.pop();
                else if(st.empty() || st.top()>0)
                st.push(cur);
            }
            else{
                // while(!st.empty() && st.top()<0 && abs(st.top()) < cur){
                //     st.pop();
                // }
                // if(!st.empty() && st.top()<0 && abs(st.top()) == cur)
                // st.pop();
                // else if(st.empty() || st.top()>0){
                //     st.push(cur);
                // }
                st.push(cur);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        // reverse(ans.begin() , ans.end());
        return ans;
    }
};