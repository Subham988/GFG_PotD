class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int base=1;
            int k=0;
            for(int i=s.length()-1;i>=0;i--)
            {
                int temp=s[i]-'0';
                k=(k+base*temp)%m;
                //cout<<k<<" ";
                base=(base*2)%m;
            }
            return k%m;
        }
};