class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        for(int i=0;i<(2<<len)/2;i++){
            List<Integer> list = new ArrayList<>();
            for(int j=0;j<len;j++){
                if(((i>>j)&1)!=0){
                    list.add(nums[j]);
                }
            }
            ans.add(new ArrayList<>(list));
        }
        return ans;
    }
}