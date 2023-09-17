#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<double> arr = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1.1};
    int n=arr.size();
    double tot = 0;
    double ans;
    for(int i=0;i<n;i++){
        tot += arr[i]*(i+1);
    }
    if(tot==210){
        cout<<"No heavy bottle";
        return 0;
    }
    double num=tot-210;
    ans=num*10;
    cout<<"The heavy bottle number is: "<<ans;
    return 0;
}