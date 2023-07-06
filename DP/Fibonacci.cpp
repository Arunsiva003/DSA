#include <iostream>
#include <vector>
using namespace std;

//recursion
int fib(int n){
    if(n<=1) return n; 
    return fib(n-1)+fib(n-2);
}


//recursion with memoization

int fib(int n,vector<int>& dp){
    if(n<=1) return n; 
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-1)+fib(n-2);
}


//tabbulation

int fib_tab(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//Space optimized Tabulation

int fib_tab2(int n){
    vector<int> dp(n+1,-1);
    int prev2=0;
    int prev=1;
    for(int i=2;i<=n;i++){
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
    }
    return prev;
}



int main(){
    int n;
    cout<<"Enter the number : \n";
    n=10;
    vector<int> dp(n+1,-1);
    cout<<fib(n)<<"\n";
    cout<<fib(n,dp)<<"\n";
    cout<<fib_tab(n)<<"\n";
    cout<<fib_tab2(n)<<"\n";

    return 0;
}