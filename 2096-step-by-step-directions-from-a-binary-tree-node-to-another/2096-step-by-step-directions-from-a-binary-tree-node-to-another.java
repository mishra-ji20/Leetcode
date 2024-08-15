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
    public boolean getPath(TreeNode root,int dest ,StringBuilder path){
        // System.out.println(path);
        
        if(root == null){
            // System.out.println("1");
            return false ;
        }
        if(root.val == dest){
            // System.out.println("1");
            return true;
        }
        path.append("L");
       if( getPath(root.left,dest,path)){
           return true;
       }
        path.setLength(path.length()-1);
        path.append("R");
       
        if( getPath(root.right,dest,path)){
            return true;
        }
        path.setLength(path.length()-1);
        return false;
        
        
    }
    public String getDirections(TreeNode root, int startValue, int destValue) {
        
        // System.out.println(x.val);
        StringBuilder start = new StringBuilder();
        StringBuilder dest = new StringBuilder();
        StringBuilder path =new StringBuilder();
        getPath(root,startValue,start);                
        getPath(root,destValue,dest);
        int index =0;
        for(index=0 ;index<start.length() && index<dest.length();index++){
            if(start.charAt(index)!=dest.charAt(index)){
                break;
            }
        }
        path.append("U".repeat(start.length()-(index)));
        path.append(dest.substring(index));
        return path.toString();
        
        
    }
}