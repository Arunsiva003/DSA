#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int arr2[]={9,8,7};
    int arr3[8];
    int sum=0;

    for(int i=0;i<5;i++){
        arr3[i]=arr[i];
        cout<<arr3[i];
        sum+=arr3[i] ;   }
    for(int i=0;i<3;i++){
        arr3[5+i]=arr2[i];
        cout<<arr3[5+i];
        sum+=arr3[5+i];
    }

    cout<<"ans :"<<sum/8;
    return 0;
}