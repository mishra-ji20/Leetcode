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
    int recur(TreeNode root,int []dp){
        int flag=0;
        int x=0;
        dp[root.val]++;
        if(root.left==null){
            flag++;
        }else{
            x+=recur(root.left,dp);
        }
        if(root.right==null){
            flag++;
        }else{
            x=x+recur(root.right,dp);
        }
        if(flag==2){
            int check=0;
            for(int i=0;i<dp.length;i++){
                if(dp[i]%2==1){
                    check++;
                }
            }
            if(check<2)
                x++;
        }
        dp[root.val]--;
        return x;
    }
    public int pseudoPalindromicPaths (TreeNode root) {
        
        int []dp=new int[10];
        return recur(root,dp);
    }
}