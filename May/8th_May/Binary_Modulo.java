class Solution{
	int modulo(String s, int m) {
		//Write your code here
		int base=1;
            int k=0;
            for(int i=s.length()-1;i>=0;i--)
            {
                int temp=s.charAt(i)-'0';
                k=(k+base*temp)%m;
                base=(base*2)%m;
            }
            return k%m;
	}
}