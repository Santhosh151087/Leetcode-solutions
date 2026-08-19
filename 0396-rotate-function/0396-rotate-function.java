class Solution {
    public int maxRotateFunction(int[] nums) {
        long sum = 0;
        long prev = 0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            prev+=(i * nums[i]);
        }
        // System.out.print(prev);
        long max = prev;
        
        int len = nums.length;
        for(int i=len-1;i>0 ;i--){
            long cur = prev - (len * nums[i]) + sum;
            prev = cur;
            max = Math.max(max , cur);
        }
        return (int)max;
    }
}