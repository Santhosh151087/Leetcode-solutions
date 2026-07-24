class Solution {
public:
    int characterReplacement(string s, int k) {
        long left = 0;
        long right = 0;
        vector<long> freq(26 , 0);
        long maxF = 0;
        long ans = 0;
        while(right<s.size()){
            freq[s[right]-'A']++;
            maxF = max(maxF , freq[s[right]-'A']);
            while(right - left+1 - maxF >k){
                
                freq[s[left]-'A']--;
                left++;
                for(int i=0;i<26;i++){
                    maxF = max(maxF ,freq[i]);
                }
            }
            ans = max(ans , right - left+1);
            right++;
        }
        return (int)ans;
    }
};