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
    int recur(TreeNode root,int freq){
        int x=0;
        freq=freq^(1<<root.val);
        if(root.left==null && root.right==null){
            if(((freq) &(freq-1))==0){
              return 1;  
            }
        }
        if(root.right!=null){
            x=x+recur(root.right,freq);

        }
        if(root.left!=null){
            x=x+recur(root.left,freq);
        }
        return x;
        
    }
    public int pseudoPalindromicPaths (TreeNode root) {
        
        return recur(root,0);
    }
}