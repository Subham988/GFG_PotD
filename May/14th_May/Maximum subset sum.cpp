class Solution {
  public:
    long long solve(int n,vector<int> &arr,int index,int indication,vector<vector<long long>> &dp){
        if(index==n)return 0;
        if(dp[index][indication]!=-1)return dp[index][indication];
        long long a=INT_MIN,b=INT_MIN;
        if(indication==1){
            b = solve(n,arr,index+1,0,dp);
        }
        a = arr[index]+solve(n,arr,index+1,1,dp);
        return dp[index][indication]=max(a,b);
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long>> dp(N,vector<long long>(2,-1));
        return solve(N,A,0,1,dp);
    }
};