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
    TreeNode lowestCommonAncestor ;
    StringBuilder start;
    StringBuilder dest;
    public boolean getStartPath(TreeNode root, int dest ,StringBuilder path){
        if(root == null){
            return false;
        }
        if(root.val == dest){
            this.start = path;
            return true;
        }
        path.append("U");
        if(getStartPath(root.left,dest,path)){
            return true;
        }
        
        if(getStartPath(root.right,dest,path)){
            return true;
        }
        path.setLength(path.length() - 1);
        return false;
        
    }
    public boolean getDestPath(TreeNode root,int dest ,StringBuilder path){
        // System.out.println(path);
        
        if(root == null){
            // System.out.println("1");
            return false ;
        }
        if(root.val == dest){
            // System.out.println("1");
            this.dest = path;
            return true;
        }
        path.append("L");
       if( getDestPath(root.left,dest,path)){
           return true;
       }
        path.setLength(path.length()-1);
        path.append("R");
       
        if( getDestPath(root.right,dest,path)){
            return true;
        }
        path.setLength(path.length()-1);
        return false;
        
        
    }
    public  boolean getlowestCommonAncestor(TreeNode root ,int startValue, int destValue){
        if(root == null){
            return false;
        }
        boolean rightFlag = getlowestCommonAncestor(root.right,startValue ,destValue);
        boolean leftFlag  = getlowestCommonAncestor(root.left,startValue ,destValue);
        
        boolean selfFlag = (root.val == startValue || root.val == destValue) ;
        
        if((rightFlag & leftFlag) || (rightFlag & selfFlag) || (leftFlag & selfFlag)  ){
            lowestCommonAncestor =root;
        }
         return (rightFlag | leftFlag | selfFlag); 
        
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        getlowestCommonAncestor(root,startValue,destValue);
        
        var x= lowestCommonAncestor;
        // System.out.println(x.val);
        
        getStartPath(lowestCommonAncestor,startValue,new StringBuilder());
        
        // System.out.println(start) ;
        // System.out.println(dest);
        
        
        getDestPath(lowestCommonAncestor,destValue,new StringBuilder());
        start.append(dest);
        return start.toString();
        
    }
}