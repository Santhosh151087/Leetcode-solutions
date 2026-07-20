class Solution {
    public void reverse(int []arr , int start , int end){
        while(start<end){
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
    }
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int R = grid.length;
        int C = grid[0].length;
        int size = R*C;
        int [] arr = new int[size];
        int ind = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                arr[ind++] = grid[i][j];
            }
        }
        reverse(arr , 0 , size-1);
        k = k%(size);
        reverse(arr , 0 , k-1);
        reverse(arr , k , size-1);
        
        List<List<Integer>> list = new ArrayList<>();
        ind = 0;
        // System.out.print(Arrays.toString(arr));
         for(int i=0;i<R;i++){
            List<Integer> l = new ArrayList<>();
            for(int j=0;j<C;j++){
                l.add(arr[ind++]); 
            }
            list.add(l);
        }
        return list;
    }
}