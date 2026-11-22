class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> level;
    void DFS(string goal , string cur , vector<string>& arr ){
        if(cur == goal){
            vector<string> temp = arr;
            reverse(temp.begin() , temp.end());
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<cur.size();i++){
                for(int j=0;j<26;j++){
                    char c = 'a' + j;
                    string str = cur;
                    str[i] = c;
                    if(level.contains(str) && level[str]+1 ==level[cur]){
                        arr.push_back(str);
                        DFS(goal , str , arr);
                        arr.pop_back();
                    }
                }
            }
        
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> wl(wordList.begin(), wordList.end());
        if (!wl.contains(endWord))
            return {};
        queue<string> qu;
        if(wl.contains(beginWord))
        wl.erase(beginWord);
        qu.push(beginWord);
        level[beginWord] = 1;
        while(!qu.empty()){
            int size = qu.size();
            for(int i=0;i<size;i++){
                string cur = qu.front();
            qu.pop();
            for(int i=0;i<cur.size();i++){
                for(int j=0;j<26;j++){
                    char c = 'a' + j;
                    string str = cur;
                    str[i] = c;
                    if(wl.contains(str)){
                        wl.erase(str);
                        level[str] = level[cur] + 1;
                        qu.push(str);
                    }
                }
            }
            }
        }
        vector<string> arr;
        arr.push_back(endWord);
        DFS(beginWord , endWord , arr );
        return ans;
    }
};