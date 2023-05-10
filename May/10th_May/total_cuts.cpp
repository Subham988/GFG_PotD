class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A)
    {
        vector<int> maxi=A;

        for(int i=1;i<N;i++)
            maxi[i]=max(maxi[i],maxi[i-1]);
        
        int mini=INT_MAX,ans=0;
        for(int i=N-2;i>=0;i--)
        {
            mini=min(mini,A[i+1]);
            if(maxi[i]+mini>=K) ans++;
        }
        return ans;
    }
};