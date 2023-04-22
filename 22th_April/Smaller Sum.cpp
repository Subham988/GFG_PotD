class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
         vector<long long> sum(n); vector<int> s;
        for(int x: arr) s.push_back(x);
        sort(begin(s),end(s));
        for(int i = 0; i < n; i++) 
            sum[i] +=  (i>0) ? sum[i-1] + s[i] : s[i];
            
        vector<long long> ans;
        for(int x: arr) {
           int l = 0, r = n-1, idx = -1;
           while(l <= r) {
               int mid = l + (r-l)/2;
               if(x > s[mid]) idx = mid , l = mid+1;
               else r = mid - 1;
           }
           ans.push_back(idx >= 0 ? sum[idx]: 0);
        }
        return ans;
    }
};