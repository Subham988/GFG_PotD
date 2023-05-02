#include<algorithm>
#include<iostream>
using namespace std;

// this solution made br subham agrahari

#include<vector>
class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
         //code here
        int count=0;
        sort(arr.begin(), arr.begin()+(n/2));
        sort(arr.begin()+(n/2), arr.end());
        
        int j=n/2;
        for(int i=0 ; i< n/2 ; i++){
            while(j<n && arr[i]>=arr[j]*5){
                j++;
            }
            count += j-n/2;
        }
        return count;
    }
};