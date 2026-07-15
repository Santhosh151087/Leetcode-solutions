/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insert(TreeNode root  ,int val ){
        if(root == null)
        return new TreeNode(val);
        if(root.val<val)
        root.right = insert(root.right , val);
        else
        root.left = insert(root.left , val);
        return root;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = null;
        for(int i=0;i<preorder.length;i++){
            root = insert(root , preorder[i]);
        }
        return root;
    }
}