class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int child = 0;
        int cool = 0;
        int ans = 0;
        while(child <g.length && cool<s.length){
            if(g[child]<=s[cool]){
                child++;
                cool++;
                ans++;
            }
            else{
                cool++;
            }
        }
        return ans;
    }
}