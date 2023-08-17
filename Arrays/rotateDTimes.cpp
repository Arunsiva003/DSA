#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> arr = {1,2,3,4,5,6};
    int d = 2;
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
    for(int x:arr){
        cout<<x<<" ";
    }
    return 0;

}