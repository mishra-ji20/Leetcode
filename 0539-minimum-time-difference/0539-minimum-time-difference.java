import java.time.LocalTime;
import java.time.Duration;
class Solution {
    int getDiffernceBetweenTimes(String time1, String time2){
        LocalTime l1 =
               LocalTime.of(Integer.parseInt(time1.substring(0,2)),Integer.parseInt(time1.substring(3,5)));
        LocalTime l2 =
               LocalTime.of(Integer.parseInt(time2.substring(0,2)),Integer.parseInt(time2.substring(3,5)));
        
        return (int)Duration.between(l1,l2).toMinutes();   
    }
    public int findMinDifference(List<String> timePoints) {
        Collections.sort(timePoints,new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });
        int res = getDiffernceBetweenTimes(timePoints.get(0),timePoints.get(timePoints.size()-1));
        int ans = Math.min(res,(60*24)-res);
        for(int i=1;i<timePoints.size();i++){
            
            ans = Math.min(ans,getDiffernceBetweenTimes(timePoints.get(i-1),timePoints.get(i)));
        }
        return ans;
        
        
        
        
    }
}