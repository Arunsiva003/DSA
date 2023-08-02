#include <bits/stdc++.h>
using namespace std;

//insertion sort
void insertionSort(vector<int>& arr){
    for (int i = 1 ;i <arr.size(); ++i) {
        //element to be inserted
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key )
        swap(arr[j+1],arr[j]);
        }
        return;
        }


int main(){
    vector<int> arr;
    arr={2,3,7,4,5};
    int n=5;
    insertionSort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
