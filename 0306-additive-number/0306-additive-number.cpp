#define ll long long int
class Solution {
public:
   
    bool isAdditiveNumber(string num) {
       int len = num.size();
       for(int f = 1;f <=len/2;f++){
        if(num[0]=='0' && f>1) break;
            for(int  s = 1 ; len - f - s >=max(f , s) ; s++){
                if(num[f]=='0' && s>1) break;
                ll fn = stoll(num.substr(0 , f));
                ll sn = stoll(num.substr(f , s));
                string  rem = num.substr(f+s);
                while(rem.size()>0){
                ll total = fn+sn;
                string total_str = to_string(total);
                if(rem.find(total_str)==0){
                    fn = sn;
                    sn = total;
                    rem = rem.substr(total_str.size());
                }
                else
                break;

                }
                if(rem.size()==0)
                return true;
               
            }
       }
       return false;
        
    }
};