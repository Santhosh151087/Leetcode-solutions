class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int[] pls(int[] nums, boolean small) {
        Stack<Pair> st = new Stack<>();
        int len = nums.length;
        int[] ans = new int[len];
        for (int i = 0; i < len; i++) {
            if (small) {
                while (!st.empty() && st.peek().first >= nums[i])
                    st.pop();
            }

            else {
                while (!st.empty() && st.peek().first <= nums[i])
                    st.pop();
            }

            if (st.empty()) {

                ans[i] = -1;

            }

            else
                ans[i] = st.peek().second;
            st.push(new Pair(nums[i], i));
        }
        return ans;
    }

    public int[] nls(int[] nums, boolean small) {
        Stack<Pair> st = new Stack<>();
        int len = nums.length;
        int[] ans = new int[len];
        for (int i = len - 1; i >= 0; i--) {
            if (small) {
                while (!st.empty() && st.peek().first > nums[i])
                    st.pop();
            }

            else {
                while (!st.empty() && st.peek().first < nums[i])
                    st.pop();
            }

            if (st.empty()) {

                ans[i] = len;

            }

            else
                ans[i] = st.peek().second;
            st.push(new Pair(nums[i], i));
        }
        return ans;
    }

    public void print(int[] arr) {
        for (int n : arr)
            System.out.print("" + n + " ");
        System.out.println();
    }

    public long subArrayRanges(int[] nums) {
        int[] pl = pls(nums, false);
        int[] nl = nls(nums, false);
        int[] ps = pls(nums, true);
        int[] ns = nls(nums, true);
        long  ans = 0;
        long l , r , max , min;
        for(int i=0;i<nums.length;i++){
            l = i - pl[i];
            r = nl[i] - i;
            max = l * r  * nums[i];
            l = i-ps[i];
            r = ns [i] - i;
            min = l*r* nums[i];
            ans +=(max - min);
        }
        return ans;
    }
}