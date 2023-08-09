#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int> rank, parent;
    
public:

    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUPar(int node){
        if(parent[node]==node) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u==ulp_v) return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

};


int main(){
    cout<<"Hello World\n";

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(3,4);

    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    if(ds.findUPar(1)==ds.findUPar(6)) cout<<"same\n";
    else cout<<"NotSame\n";
    ds.unionByRank(5,6);
    if(ds.findUPar(1)==ds.findUPar(6)) cout<<"same\n";
    else cout<<"NotSame\n";
    return 0;
}