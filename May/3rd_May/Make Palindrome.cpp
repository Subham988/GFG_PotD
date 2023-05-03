class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
         unordered_map<string,int> mp;
        for(auto it: arr)mp[it]++;
        for(auto it: arr){
            string rs = it;
            reverse(rs.begin(),rs.end());
            if(mp[rs]==mp[it])continue;
            else return false;
        }
        return true;
    }
};