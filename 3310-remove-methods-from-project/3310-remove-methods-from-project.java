class Solution {

    void dfs(int n , int k , Map<Integer , ArrayList<Integer>> adj , boolean [] visited){
        if(visited[k])
        return;
        visited[k] = true;
        ArrayList<Integer> curK = adj.get(k);
        if(curK ==null)
        return;
        for(int cur : curK){
            dfs(n,cur , adj , visited);
        }
    }

    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {
        boolean [] visited = new boolean[n];
        Map<Integer , ArrayList<Integer>> adj = new HashMap<>();
        for(int [] cur: invocations){
            if(adj.containsKey(cur[0])){
                  adj.get(cur[0]).add(cur[1]);
            }
            else {

                adj.put(cur[0], new ArrayList<>());
                adj.get(cur[0]).add(cur[1]);
            }
            
        }
        dfs(n , k , adj , visited);
       boolean [] newvisited = new boolean[n];
        List<Integer> ans = new ArrayList<>();
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(n , i , adj , newvisited);

            }
        }
        // for(int i)
        for(int i=0;i<n;i++){
            if(visited[i] && newvisited[i]){
                List<Integer> a = new ArrayList<>();
                for(int j=0;j<n;j++){
                    a.add(j);
                }
                return a;
            }
            else if(!visited[i]) ans.add(i);
        }
        return ans;
    }
}