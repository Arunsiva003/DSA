//{ Driver Code Starts


/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1

Your Task:  
You don't need to read input or print anything. Your task is to complete the function numProvinces() which takes an integer V and an adjacency matrix adj as input and returns the number of provinces. adj[i][j] = 1, if nodes i and j are connected and adj[i][j] = 0, if not connected.
*/
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(int node, vector<int> adjLis[], int vis[]){
        vis[node]=1;
        // ans.push_back(node);
        for(auto it : adjLis[node]){
            if(!vis[it]){
                dfs(it,adjLis,vis);
            }
        }
    }
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjLis[V+1];
        
        for(int i=1;i<=V;i++){
            for(int j=i+1;j<=V;j++){
                if(adj[i-1][j-1]==1){ 
                    adjLis[i].push_back(j);
                    adjLis[j].push_back(i);
                }
            }
        }
        // for(int i=1;i<=V;i++){
            
        //     for(int it: adjLis[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        int vis[V+1]={0};
        int cnt=0;
        for(int i=1;i<=V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjLis,vis);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends