class Solution {
    boolean [] visited;
    public void dfs(int [][] isConnected  , int R){
        for(int i=0;i<isConnected.length ; i++){
            if(isConnected[R][i] ==1 && !visited[i]){
                visited[i]= true;
                dfs(isConnected , i);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int N = isConnected.length;
        visited = new boolean[N];
        int count = 0;
        for(int row=0;row<N;row++){
            for(int col=0;col<N;col++){
                if(isConnected[row][col]==1 && !visited[row] ){
                count++;
                visited[row] = true;
                dfs(isConnected ,row);
            }
            }

        }
        return count;
    }
}