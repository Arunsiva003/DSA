#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> a = {1,3,3,7,3};
    int size=a.size();
    int ans=a[0],cnt=1;
    for(int i=1;i<size;i++){
        if(ans==a[i]) cnt++;
        else cnt--;
        if(cnt==0){
            ans=a[i];
            cnt=1;
        }
    }
    cnt=0;
    for(int i=0;i<size;i++){
        if(a[i]==ans) cnt++;
    }
    if(cnt>size/2){
        cout<<ans;
    }
    else{
        cout<<-1;
    }
    return 0;
}