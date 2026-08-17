class Pair{
    int val , ind;
    Pair(int val , int ind){
        this.val = val;
        this.ind = ind;
    }
}
class Solution {
    public int [] pse(int [] arr){
        int [] ans = new int[arr.length];
        Stack<Pair> st = new Stack<>();
        for(int i=0;i<arr.length;i++){
            while(!st.empty() && st.peek().val >= arr[i]){
                    st.pop();
            }
            if(st.empty())
            ans[i] = -1;
            else
            ans[i] = st.peek().ind;
            st.push(new Pair(arr[i] , i));

        }
        return ans;
    }
     public int [] nse(int [] arr){
        int [] ans = new int[arr.length];
        Stack<Pair> st = new Stack<>();
        for(int i=arr.length-1;i>=0;i--){
            while(!st.empty() && st.peek().val > arr[i]){
                    st.pop();
            }
            if(st.empty())
            ans[i] = arr.length;
            else
            ans[i] = st.peek().ind;
            st.push(new Pair(arr[i] , i));

        }
        return ans;
    }
    public void print(int [] arr){
        for(int n:arr)
        System.out.print(n+" ");
        System.out.println();
    }
    public int largestRectangleArea(int[] heights) {
        int [] ps = pse(heights);
        int [] ns = nse(heights);
        int ans = -1;
        // print(ps);
        // print(ns);
        for(int i=0;i<heights.length;i++){
            int left = i - ps[i] -1 ;
            int right = ns[i] - i;
            ans = Math.max(ans , (left + right) * heights[i]);
        }
        return ans;
    }
}