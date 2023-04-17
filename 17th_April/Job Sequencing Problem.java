class Solution
{
    int[] JobScheduling(Job arr[], int n)
    {
        // Your code here
        int maxDeadline = 1;
        for(Job job : arr){
            maxDeadline = Math.max(maxDeadline , job.deadline);
        }
        
        Arrays.sort(arr , (a,b) -> b.profit - a.profit);
        
        int[] slots = new int[maxDeadline+1];
        Arrays.fill(slots,-1);
        
        int[] ans = {0,0} ;
        
        for(Job j : arr){
            for(int i=j.deadline ; i>0 ; i--){
                if(slots[i]==-1){
                    slots[i]=1;
                    ans[0]++;
                    ans[1] += j.profit;
                    break;
                }
            }
        }
        return ans;
    }
