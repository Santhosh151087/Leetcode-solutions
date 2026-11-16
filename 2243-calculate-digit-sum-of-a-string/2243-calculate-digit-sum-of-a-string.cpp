class Solution {
public:
    
    string solve(string s){
        cout<<s<<endl;
        int i=0;
        int total = 0;
        while(i < s.size()){
            int cur = s[i] -'0';
            // cout<<cur<<" ";
            i++;
            total+=cur;
        }
        return to_string(total);

    }
    string digitSum(string s, int k) {

        int len = s.size();
        if(len<=k)
        return s;
        string cur = "";
        for(int start=0;start<len;start+=k){
            int size = k;
            if(start+k>len)
            size =  len - start;
            
            cur+=(solve(s.substr(start , size)));
        }
        return digitSum(cur , k);
    }
};