class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int right = arr.size()-1;
        int left = k-1;
        int sum = 0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int ans = sum;
        if(k==arr.size())
        return sum;
        
        while(left>=0){
            sum -=arr[left];
            sum+=arr[right];
            left --;
            right--;
            ans = max(ans , sum);
        }
        return ans;

    }
};