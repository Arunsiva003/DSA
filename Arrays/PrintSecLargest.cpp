#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {2,4,3,1,3,5,4,4,3};
    int n=arr.size();


    int first = -1, sec = -1;
    for (int i = 0; i < n; i++) {
        if (first < arr[i]) {
            sec = first;
            first = arr[i];
        } else if (arr[i] > sec && arr[i] < first) {
            sec = arr[i];
        }
    }
    cout<<sec;
    return 0;
}