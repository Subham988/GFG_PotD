

class Solution{
public:
     bool makePalindrome(int n,vector<string> &arr){
        map<string,int> mp;
        
        for(int i = 0;i < arr.size(); i++)
        {
            string b = arr[i];
            reverse(b.begin(),b.end());
            if(mp.find(b) == mp.end())
            {
                mp[arr[i]] = 1;
            }
            else
            {
                mp[b]++;
            }
        }
        
        if(n%2 == 0)
        {
            for(auto x : mp)
            {
                if(x.second%2 != 0)return false;
            }
            return true;
        }
        else 
        {
            bool check = false;
            for(auto x : mp)
            {
                if(x.second%2 != 0 && check == false)
                {
                    string tmp = x.first;
                    reverse(tmp.begin(),tmp.end());
                    if(x.first != tmp)return false;
                    else check = true;
                }
                else if(x.second%2 != 0 && check == true)
                {
                    return false;
                }
            }
            return true;
            
        }
    }
};
