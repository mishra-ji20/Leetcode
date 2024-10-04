class Solution {
    public long dividePlayers(int[] skill) {
        int n=skill.length;
        Arrays.sort(skill);
        int teamSkill = skill[0]+skill[skill.length-1];
        long ans=0;
        for(int i=0,j=skill.length-1;i<j;i++,j--){
            if(skill[i]+skill[j]==teamSkill){
                ans+=(long)(skill[i]*skill[j]);
            }else{
                return -1;
            }
            
        }
        return ans;
    
        
    }
}