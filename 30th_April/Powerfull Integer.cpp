class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        int mx=0;
        for(int i=0;i<n;i++)mx=max(mx,intervals[i][1]);
        vector<int>v(mx+2,0);
        for(int i=0;i<n;i++){
            v[intervals[i][0]]++;
            v[intervals[i][1]+1]--;
        }
        int ans=-1;
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
            if(v[i]>=k)ans=i;
        }
        return ans;
    }
};