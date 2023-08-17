#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr1={1,2,3,4,5,5,5,5}, arr2={2,4,4,4,5,6};
    int i=0,j=0;
    int n=arr1.size(),m=arr2.size();
    vector<int> arr; 
    while(i<n && j<m){
        while(arr1[i-1]==arr1[i]) i++;
        while(arr2[j-1]==arr2[j]) j++;
        if(arr1[i]<arr2[j]){
            arr.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i]>arr2[j]){
            arr.push_back(arr2[j]);
            j++;
        }
        else{
            i++;
        }
    }
    while(i<n){
        arr.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        arr.push_back(arr2[j]);
        j++;
    }
    for(int x:arr){
        cout<<x<<" ";
    }

    return 0;
}