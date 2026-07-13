class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string num = "123456789";
        int ls = 0;
        int hs = 0;
        int temp = low;
        while(temp>0){
            ls++;
            temp/=10;
        }
        temp = high;
         while(temp>0){
            hs++;
            temp/=10;
        }
        // cout<<ls<<" "<<hs;

        for(int size = ls;size<=hs;size++){

            for(int start = 0 ;start<10 - size ;start++){
                string cur = num.substr(start , size);
                int curnum = stoi(cur);
                if(curnum>high)
                break;
                if(curnum>=low)
                ans.push_back(curnum);
            }
        }
        return ans;
        
        
    }
};