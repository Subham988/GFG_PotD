#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int solve(int a, int b, int c) {
        // your code start here
        int maxi = max(a , max(b,c));
        int mini = min(a , min(b,c));
        int md = a+b+c - maxi- mini;
        
        if(maxi > (md + mini +1)*2) return -1;
        return a+b+c;

        // your code end here
    }
};