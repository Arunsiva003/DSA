

#include <bits/stdc++.h>
using namespace std;



int helper(int ind,vector<int>& arr,vector<int>& dp,int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    for(int i=1;i<=k;i++){
        int way1 = helper(ind-1,arr,dp,k)+abs(arr[ind]-arr[ind-1]);
        int way2=INT_MAX;
        if(ind>1)
            way2 = helper(ind-2,arr,dp,k)+abs(arr[ind]-arr[ind-2]);
        dp[ind]=min(way1,way2);
}
    return dp[ind];
}

int frogJump1(int n, vector<int> &arr,int k) {
    vector<int> dp(n,-1);
    return helper(n-1,arr,dp,k);
}


int main(){
    vector<int> arr;
     arr = {10,30,40,50,20};
     int k=3;
    cout<<frogJump1(4,arr,2);
    return 0;
}