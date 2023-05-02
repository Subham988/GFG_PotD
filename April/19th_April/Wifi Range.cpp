class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int fre[N+1]={0};
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                int left=max(i-X,0);
                int right=min(i+X,N-1);
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
};
