#include <bits/stdc++.h> 
using namespace std;

// Same msnae problem but here the array is circular ie. the first and last elements are adjacent.


long long msnae(vector<long long> &nums){
    vector<long long> dp(nums.size());
    dp[0]=nums[0];
    for (long long i = 1; i < nums.size(); i++) {
      long long take = nums[i];
      if (i-2 >= 0)
        take += dp[i - 2];
      long long nottake = 0 + dp[i - 1];
      dp[i] = max(take, nottake);
    }
    return dp[nums.size() - 1];
}
long long int houseRobber(vector<int>& v)
{
    // Write your code here.
    int n = v.size();
    if (n == 0) return 0;
    if (n == 1) return v[0];

    vector<long long> temp1(v.begin(), v.end() - 1);
    vector<long long> temp2(v.begin() + 1, v.end());

    return max(msnae(temp1), msnae(temp2));
}

int main(){
    vector<int> inp;
    inp = {1,5,1,2,6};
    cout<<houseRobber(inp);
}