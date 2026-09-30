// the idea is based on slope if the slope increase increase the valuse , if slope remains same add 1 , if slope decreases note the last value and then increse by 1 for all finally add which is greatest 


class Solution {
public:
    int candy(vector<int>& arr) {
        int N = arr.size();
        int ans = 0;
        int ind = 0;
        int peek = 1;
        while (ind < N) {
            if (ind == 0 || arr[ind - 1] == arr[ind]) {
                ans += 1;
                ind++;
                continue;
            }
            peek = 1;

            while (ind < N && arr[ind - 1] < arr[ind]) {
                peek++;
                ans += peek;
                ind++;
                
            }
            
            if(ind<N && arr[ind-1] > arr[ind]){
                int speek = 1;
                ans-=peek;
                while(ind <N && arr[ind-1] > arr[ind]){
                ans+=speek;
                ind++;
                speek++;
            }
            ans+=max(peek , speek);
            }
            
            
        }

        return ans;
    }
};