#include <bits/stdc++.h>
using namespace std;
/*
Sample Input 1:
2
3
1 2 5 
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
*/
int helper(int ind,int last,vector<vector<int>> &points,vector<vector<int>>& dp){
    if(ind==0){
        int maxi=INT_MIN;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(points[ind][i],maxi);
            }
        }
        return maxi;
    }

    if(dp[ind][last]!=-1) return dp[ind][last];
    int maxi = INT_MIN;
    for(int i=0;i<=2;i++){
        if(i!=last){
            maxi = max(maxi,points[ind][i]+helper(ind-1,i,points,dp));
        }
    }
    return dp[ind][last]=maxi;

}
int ninjaTrainingR(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return helper(n-1,3,points,dp);

}


int ninjaTrainingT(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][2],points[0][0]);
    dp[0][2] = max(points[0][1],points[0][0]);
    dp[0][3] = max(points[0][1],max(points[0][2],points[0][0]));
    

    for(int i=1;i<n;i++){
        
        for(int last=0;last<=3;last++){
            dp[i][last] = 0;

            for(int task=0;task<=2;task++){
                if(task!=last){
                    int point = points[i][task] + dp[i-1][task];
                    dp[i][last]=max(dp[i][last],point);
                }
            }

        }
        
    }return dp[n-1][3];

}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    cout<<ninjaTrainingT(n,arr)<<endl;
}