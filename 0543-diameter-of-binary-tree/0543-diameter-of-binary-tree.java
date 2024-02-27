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
    public int x;
    public int diameterOfBinaryTree(TreeNode root) { 
            depth(root);
        return x-1;
    }
    public int depth(TreeNode root){
        if(root==null){
            return 0;
        }
        int leftHeight= depth(root.left);
        int rightHeight=depth(root.right);
        x=Math.max(x,leftHeight+rightHeight+1);
        return Math.max(leftHeight,rightHeight)+1;
        
    }
    
}