class Solution {
    public String removeKdigits(String num, int k) {
        if(num.length() == k)
        return "0";
        Stack<Character> st = new Stack<>();
        for(char c : num.toCharArray()){
            if(st.empty() || k ==0){
                st.push(c);
            }
            else{
                if(st.peek()- '0' > c-'0'){
                    while(!st.empty() && k>0 && st.peek() - '0' > c-'0'){
                         k--;
                         st.pop();
                    }
                   
                }
                st.push(c);
              
            }

        }
        // System.out.print(k);
        StringBuilder ans = new StringBuilder();
        while(!st.empty()){
            ans.append(st.pop());

        }
        
        // System.out.print(k);
        ans.reverse();
        if(k >=ans.length())
        return "0";
        int ind = 0;
        while(ind < ans.length() && ans.charAt(ind)=='0'){
                ind++;
                
        }
        String a = ans.substring(ind);
        if(k >=a.length())
        return "0";
        return a.substring(0 , a.length() - k);
    }
}