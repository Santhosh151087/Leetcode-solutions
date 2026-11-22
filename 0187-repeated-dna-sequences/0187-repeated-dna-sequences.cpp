class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    
    vector<string> ans;
    map<char , int> value;
    value['A'] = 0;
    value['C'] = 1;
    value['G'] = 2;
    value['T'] = 3;
    int N = s.size();
    int hash=0;
    unordered_set<int> visited;
    unordered_set<int> repeated;
    for(int i=0;i<N;i++){
        hash = (hash <<2) | value[s[i]];
        hash = ((1<<20) -1 ) & hash;
        
        if(i>=9){
            // cout<<i<<" "<<hash<<endl;
            if(visited.contains(hash) && !repeated.contains(hash)){
                ans.push_back(s.substr(i-9 , 10));
                repeated.insert(hash);
            }
            else
            visited.insert(hash);
        }

    }
    return ans;
    }
};