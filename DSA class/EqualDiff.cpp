#include <bits/stdc++.h>
using namespace std;

void recur(int i, vector<int>& ds, int& ans, vector<int>& arr){
    if(i<0){
        int diff=abs(ds[0]-ds[1]);
        for(int i=2;i<ds.size();i++){
            if(diff != abs(ds[i-1]-ds[i])) return;
        }
        int x=ds.size();
        ans = max(ans, x);
        return;
    }
    
    ds.push_back(arr[i]);
    recur(i-1, ds, ans, arr);
    ds.pop_back();
    recur(i-1, ds, ans, arr);
}


int main() {
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        if(arr.size() <= 2) cout << 0 << "\n";
        else { 
            int ans = INT_MIN;
            vector<int> ds;
            recur(n-1, ds, ans, arr);
            cout << n - ans << "\n";
            t--;
        }
    }
    return 0;
}
