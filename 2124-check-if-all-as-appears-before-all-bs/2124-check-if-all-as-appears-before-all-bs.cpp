class Solution {
public:
    bool checkString(string s) {
        bool gotb = false;
        for(char c : s){
            if(c=='b')
            gotb = true;
            if(c=='a' && gotb)
            return false;
        }
        return true;
    }
};