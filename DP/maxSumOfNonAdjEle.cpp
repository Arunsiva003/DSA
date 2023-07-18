#include <bits/stdc++.h>
using namespace std;

int helper(int ind, vector<int>& arr){
    if(ind==0) return arr[0];

    int nottake=helper(ind-1,arr);
    int take=-1e8;
    if(ind-2>=0) take=arr[ind]+helper(ind-2,arr);
    return max(take,nottake);
}

// int msonaeR(vector<int>& arr){
//     vector<int> arr={2,6,3,1,9};
//     int n=arr.size();
//     return helper(n-1,arr);
// }

int helper(int ind, vector<int>& arr,vector<int>& dp){
    if(ind==0) return arr[0];
    if(dp[ind]!=-1) return dp[ind];
    int nottake=helper(ind-1,arr,dp);
    int take=-1e8;
    if(ind-2>=0) take=arr[ind]+helper(ind-2,arr,dp);
    return dp[ind]=max(take,nottake);
}

int msonaeM(vector<int>& arr){
    int n=arr.size();
    vector<int> dp(n,-1);
    return helper(n-1,arr,dp);
}

int msonaeT(vector<int>& arr){
    int n=arr.size();
    vector<int>dp(n,0);
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        int nottake=dp[i-1];
        int take=-1e8;
        if(i-2>=0) take=arr[i]+dp[i-2];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}

int main(){
    vector<int> arr;
    arr={2,6,3,1,9};
    cout<<msonaeT(arr);
    return 0;
}