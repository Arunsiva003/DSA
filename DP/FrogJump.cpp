// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

#include <bits/stdc++.h>
using namespace std;


//Recursion with memoization

int helper(int ind,vector<int>& arr,vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int way1 = helper(ind-1,arr,dp)+abs(arr[ind]-arr[ind-1]);
    int way2=INT_MAX;
    if(ind>1)
        way2 = helper(ind-2,arr,dp)+abs(arr[ind]-arr[ind-2]);
    return dp[ind]=min(way1,way2);
}

int frogJump1(int n, vector<int> &arr) {
    vector<int> dp(n,-1);
    return helper(n-1,arr,dp);
}


//Tabulation
int frogJump2(int n, vector<int> &arr) {
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int way1=dp[i-1]+abs(arr[i]-arr[i-1]);
        int way2=INT_MAX;
        if(i>1)
            way2 = dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]=min(way1,way2);
    }
    return dp[n-1];
}


//Space optimized Tabulation

int frogJump3(int n, vector<int> &arr) {
    int prev=0,prev2=0,curr;
    for(int i=1;i<n;i++){
        int way1=prev+abs(arr[i]-arr[i-1]);
        int way2=INT_MAX;
        if(i>1)
            way2 = prev2+abs(arr[i]-arr[i-2]);
        curr=min(way1,way2);
        prev2=prev;
        prev=curr;

    }
    return prev;
}




int main(){
    vector<int> arr;   
     arr = {10,20,30,10};
    cout<<frogJump3(4,arr);
    return 0;
}