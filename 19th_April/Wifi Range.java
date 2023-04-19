class Solution 
{ 
    boolean wifiRange(int N, String S, int X) 
    { 
        // code here
        int[] fre=new int[N+1];
        for(int i=0;i<N+1;i++){
            fre[i]=0;
        }
        for(int i=0;i<N;i++){
            if(S.charAt(i)=='1'){
                int left=Math.max(i-X,0);
                int right=Math.min(i+X,N-1);
                fre[left]++;
                fre[right+1]--;
            }
        }
        for(int i=0;i<N;i++){
            if(i>0){
                fre[i]+=fre[i-1];
            }
            if(fre[i]==0)
                return false;
        }
        return true;
    }
} 