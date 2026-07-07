class Solution {
    public int[] singleNumber(int[] nums) {
        int total = 0;
        for(int n:nums)total^=n;
        int count  = 0;
        while(((total>>count)&1)==0)count++;
        int xor1 = 0;
        int xor2 = 0;
        for(int n:nums){
            if(((n>>count)&1)==0)
            xor1^=n;
            else
            xor2^=n;
        }
        return new int []{xor1, xor2};
    }
}