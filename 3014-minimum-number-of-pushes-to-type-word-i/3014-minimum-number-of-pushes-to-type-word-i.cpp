class Solution {
public:
    int minimumPushes(string word) {
         vector<int> map(26 , 0);
        for(char c: word){
            map[c-'a']++;
        }
        sort(map.begin() , map.end());
        reverse(map.begin() , map.end());
        int count = 1;
        int ans = 0;
        for(int i=0;i<26;i++){
            if(map[i]==0)
            break;
            if(count <=8){
                ans+=map[i];
                
            }
            else if(count<=16){
                ans+=(map[i]*2);
            }
            else if(count<=24){
                ans+=(map[i]*3);
            }
            else{
                ans+=(map[i]*4);
            }

            count++;
        }
        return ans;
    }
};