class Solution {
    public int mostBooked(int n, int[][] meetings) { 
        // HashMap<Integer,Integer>mp=new HashMap<>();
        // for(int i=0;i<meetings.length;i++){
        //     mp.put(meetings[i][0],i);
        // }
        Arrays.sort(meetings,new Comparator<int[]>(){
            public int compare(int[] arr1,int []arr2){
                if(arr1[0]>arr2[0]){
                    return 1;
                }else{
                    return -1;
                }
            }
        });
        int []ans=new int[n];
        PriorityQueue<Integer>meetingRooms=new PriorityQueue<Integer>(new Comparator<Integer>(){
           public int compare(Integer x,Integer y){
               if(x>y){
                   return 1;
               }else{
                   return -1;
               }
               
           } 
        });
        for(int i=0;i<n;i++){
            meetingRooms.add(i); 
        }
        // System.out.println(meetingRooms.peek());
        PriorityQueue<long[]>occupiedMeetings=new PriorityQueue<>(new Comparator<long[]>(){
           public int compare(long[]arr1, long[] arr2){
                return arr1[0]!=arr2[0]?Long.compare(arr1[0],arr2[0]):Long.compare(arr1[1],arr2[1]);
            }
            
        });
        for(int i=0;i<meetings.length;i++){
            int meetingStartTime=meetings[i][0];
            int meetingEndTime=meetings[i][1];
            while(!(occupiedMeetings.isEmpty()) && occupiedMeetings.peek()[0]<=meetingStartTime){
                // System.out.print(occupiedMeetings.peek().get(0)+ " " +occupiedMeetings.peek().get(1)+" ");
                meetingRooms.add((int)occupiedMeetings.poll()[1]);
            }
            if(!meetingRooms.isEmpty()){
                int room=meetingRooms.poll();
                occupiedMeetings.offer(new long[]{meetingEndTime,room});
                ans[room]++;
            }else{
                long roomAvailabilityTime=occupiedMeetings.peek()[0];
                int room = (int) occupiedMeetings.poll()[1];
                occupiedMeetings.offer(new long[]{roomAvailabilityTime + meetingEndTime - meetingStartTime,room});
                ans[room]++;
            }
        }
        int maxMeeting=0;
        for(int i=1;i<n;i++){
            if(ans[maxMeeting]<ans[i]){
                maxMeeting=i;
            }
        }
        return maxMeeting;
        
        
    }
}