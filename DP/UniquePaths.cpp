/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
*/

#include <bits/stdc++.h> 
using namespace std;

int helper(int i,int j,vector<vector<int>>& dp){
	if(i==0 && j==0) return 1;
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=0) return dp[i][j];
	int left = helper(i-1,j,dp);
	int right = helper(i,j-1,dp);

	return dp[i][j]=left+right;
}

int uniquePathsR(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,0));
	return helper(m-1,n-1,dp);
}


int uniquePathsT(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m,vector<int>(n,0));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0) dp[i][j]=1;
			else{
				int right=0,down=0;
				if(i>=1){
					right+=dp[i-1][j];
				}
				if(j>=1){
					down+=dp[i][j-1];
				}
				dp[i][j] = down+right;
			}
		}

	}
	return dp[m-1][n-1];
}

int uniquePathsST(int m, int n) {
	// Write your code here.
	vector<int> prev(n,0);
	for(int i=0;i<m;i++){
		vector<int> temp(n,0);
		for(int j=0;j<n;j++){
			if(i==0 && j==0) temp[j]=1;
			else{
				int right=0,down=0;
				if(i>=1){
					right+=prev[j];
				}
				if(j>=1){
					down+=temp[j-1];
				}
				temp[j] = down+right;
			}
		}
		prev=temp;

	}
	return prev[n-1];
}

int main(){
    int m,n;
    cin>>m>>n;
    
    cout<<uniquePathsR(m,n)<<endl;
}