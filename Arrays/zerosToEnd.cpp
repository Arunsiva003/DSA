#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {2,1,0,2,3,1,0,0,2,0,3};
    int n=arr.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            j++;
        }
    }

    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;
}