class Solution {
public:
    vector<vector<bool>> visited;
    void dfs(vector<vector<int>>& image, int sr, int sc, int color , int origin){
        if(sr<0 || sr>=image.size() || sc<0 || sc >=image[0].size() || image[sr][sc]!=origin || visited[sr][sc])
        return;
        image[sr][sc] = color;
        visited[sr][sc] = true;
        dfs(image , sr+1 , sc , color , origin);
        dfs(image , sr-1 , sc , color , origin);
        dfs(image , sr , sc+1 , color , origin);
        dfs(image , sr , sc-1 , color , origin);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        visited.resize(image.size() , vector<bool>(image[0].size() , false));
        dfs(image , sr , sc , color , image[sr][sc]);
        return image;
    }
};