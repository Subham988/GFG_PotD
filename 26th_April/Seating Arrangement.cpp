class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        int i = 0;
        while(i < m && n > 0){
            if(seats[i] == 0 && ((i-1 < 0 || seats[i-1] == 0)
            && (i+1 >= m || seats[i+1] == 0))){
                n--;
                seats[i] = 1;
            }
            i++;
        }   
        if(n){
            return false;
        }
        return true;
    }  
};
