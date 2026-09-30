class Solution {
public:
    int candy(vector<int>& arr) {
        int N = arr.size();
        vector<int> left(N);
        vector<int> right(N);
        right[N-1] = 1;
        left[0] = 1;
        for(int i=1;i<N;i++){
            if(arr[i] > arr[i-1]){
                left[i] = left[i-1] +1;
            }
            else{
                left[i] = 1;
            }
        }
        for(int i=N-2;i>=0;i--){
            if(arr[i] > arr[i+1])
            right[i] = right[i+1]+1;
            else 
            right[i] = 1;
        }
        int ans = 0;
        for(int i=0;i<N;i++){
            ans+=max(left[i] , right[i]);
        }


        return ans;

    }
};