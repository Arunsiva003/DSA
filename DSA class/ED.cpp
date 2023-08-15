#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t){
	    
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    if(arr.size()<=2) cout<<0<<"\n";
        else{ 
	    sort(arr.begin(),arr.end());
	    int ans = 0;
	    int cnt=1;
	    for(int i=1;i<n;i++){
	        if(arr[i]==arr[i-1]) cnt++;
	        else{
	            ans=max(ans,cnt);
	            cnt=1;
	        }
	    }
        ans=max(ans,cnt);
	    cout<<n-ans;
        }
        t--;
	}
	    return 0;
}
