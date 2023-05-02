class Solution
{
    public long[] smallerSum(int n,int arr[])
    {
        
               long[] pref=new long[n];
        long[] ans=new long[n];
        int[] asc=new int[n];
        for (int i = 0; i < arr.length; i++) {
            asc[i]=arr[i];
        }
        Arrays.sort(asc);
        pref[0]=asc[0];
        for (int i = 1; i < n; i++) {
           pref[i]= pref[i-1] + asc[i];
        }
        for (int i = 0; i < asc.length; i++) {
            if (asc[0]==arr[i]) {
                ans[i]=0;
                continue;                
            }
            int l=0,r=n-1;
            while (l<r) {
                int mid=(l+r+1)/2;
                if(asc[mid]>=arr[i]){
                    r=mid-1;
                }
                else{
                    l=mid;
                }
            }
            ans[i]=pref[l];
        }

        return ans;
    }
}