#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {0,0,1,1,0,0,0,1,0,2,0,2,0,2,0,2};
    int n = arr.size();
    int low=0, mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            int t=arr[mid];
            arr[mid]=arr[low];
            arr[low]=t;
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            int t=arr[mid];
            arr[mid]=arr[high];
            arr[high]=t;
            high--;
        }
    }
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}