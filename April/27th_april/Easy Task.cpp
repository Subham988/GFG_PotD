class Solution{
public:
    char solve(int freq[],int k)
    {
        int count =0;
        for(int i=25;i>=0;i--)
        {
            count+=freq[i];
            if(count>=k)
                return i+'a';
        }
        return '*';
    }
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries)
    {
        vector<char> ans;
        for(int i=0;i<queries.size();i++)
        {
            int queryNumber=stoi(queries[i][0]);
            if(queryNumber==1)
            {
                int index=stoi(queries[i][1]);
                char ch=queries[i][2][0];
                s[index]=ch;
            }
            else
            {
                int leftIndex=stoi(queries[i][1]);
                int rightIndex=stoi(queries[i][2]);
                int k=stoi(queries[i][3]);
                int freq[26]={0};
                for(int k=leftIndex;k<=rightIndex;k++)
                {
                    int index=s[k]-'a';
                    freq[index]++;
                }
                char ch=solve(freq,k);
                ans.push_back(ch);
            }
        }
        return ans;
    }
};