#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {6,4,2,3,1,1,2,2,1};
    int sum=arr[0];
    int n=arr.size();
    int k=10;
    int ans=0,left=0,right=0;
    while(right<n){
        while(right<n && sum<k){
            sum+=arr[right];
            right++;
        }
        if(sum==k){
            cout<<right<<" "<<left<<"\n";
            ans = max(ans,right-left+1);
            sum-=arr[left];
            left++;
            right++;  // Corrected this line
        }
        else{
            sum-=arr[left];
            left++;
        }
    }

    cout<<ans;
    return 0;

}
