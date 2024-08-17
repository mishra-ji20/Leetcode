class Solution {
    public long maxPoints(int[][] points) {
        long [][] maxRowWise = new long[points.length+1][points[0].length];
        long maxScore = 0;
        for (int row = 1;row <= points.length;row++){
            
            for(int column =0 ;column < points[row-1].length;column++){
                maxRowWise[row][column]=maxRowWise[row-1][column] + (long)points[row-1][column] ;
                maxScore =Math.max (maxScore,maxRowWise [row][column]);
            }
            for(int column = 1 ;column <points[row-1].length;column++){
                maxRowWise [row][column] = Math.max(maxRowWise [row][column] , maxRowWise [row][column-1]-1);
                
                
            }
            for(int column = points[row-1].length-2 ;column >=0;column--){
                maxRowWise [row][column] = Math.max(  maxRowWise [row][column],maxRowWise[row][column+1]-1); 
                
                
            }
        }
        return maxScore;
        
    }
}