#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr;
    arr={2,6,3,4,1,9};
    int n=6;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}