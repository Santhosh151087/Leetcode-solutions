class Trie{
   public:
    string word;
    vector<Trie*> chars;
    
    Trie(){
        chars.resize(26 , nullptr);
    }
};

class Solution {
    public:
    vector<vector<bool>> visited;
     vector<string> ans ;
    void buildTrie(Trie* p , string word , int idx){
        int chidx = word[idx] - 'a';
        if(p->chars[chidx] == nullptr){
            p->chars[chidx] = new Trie();
        }
        Trie* curr = p->chars[chidx];
        if(idx == word.size() -1){
            curr->word = word;
            return ;
        } 
        buildTrie(curr , word , idx+1);
    }
    void dfs(vector<vector<char>>& board , Trie* root , int row , int col , int R , int C){
        if(row<0 || col <0 || row>=R || col >=C || visited[row][col])
        return;
        int chind = board[row][col] - 'a';
      
        if(root->chars[chind]==nullptr){
            return;
        }
        root = root->chars[chind];
          if(root->word.size() !=0){
            ans.push_back(root->word);
            root->word = "";
           
        }
        visited[row][col] = true;
        dfs(board , root , row+1 , col , R , C);
        dfs(board , root , row , col+1 , R , C);
        dfs(board , root , row-1 , col , R , C);
        dfs(board , root , row , col-1 , R , C);
        visited[row][col] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
     Trie* root = new Trie();
     for(string s : words){
        buildTrie(root , s , 0);
     }
     int R = board.size();
     int C = board[0].size();
     visited.resize(R , vector<bool> (C , false));
     for(int row = 0;row<R;row++){
        for(int col = 0; col<C ; col++){
            dfs(board , root , row , col , R , C);
        }
     }
   
    return ans;
    }
};