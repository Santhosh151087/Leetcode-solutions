class Solution {
    public String minWindow(String s, String t) {
        
         
        int len = Integer.MAX_VALUE;
        int start = 0;
        int left = 0;
        int [] map = new int[123];
        for(char c:t.toCharArray())map[c-'A']++;
        int count = 0;
        for(int right = 0;right<s.length();right++){
            if(map[s.charAt(right)-'A'] >0)
            count++;
           
            map[s.charAt(right)-'A']--;
            while(count == t.length()){
                if(len>right-left+1){
                     start = left;
                len = right -left+1;
                }
                map[s.charAt(left)-'A']++;
                if(map[s.charAt(left)-'A'] >0)
                count--;
                left++;
                
            }
             
        }
        if(len ==Integer.MAX_VALUE)
        return "";
    
        return s.substring(start , start+len);
    }
}