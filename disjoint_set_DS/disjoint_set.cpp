#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); // so that we could use both 0-based and 1-based indexing.
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    // along path compression
    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    //more intuitive
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
int main() {
    DisjointSet dsR(7), dsS(7);
    dsR.unionByRank(1, 2); 
    dsR.unionByRank(2, 3); 
    dsR.unionByRank(4, 5); 
    dsR.unionByRank(6, 7); 
    dsR.unionByRank(5, 6); 

    dsS.unionBySize(1, 2); 
    dsS.unionBySize(2, 3); 
    dsS.unionBySize(4, 5); 
    dsS.unionBySize(6, 7); 
    dsS.unionBySize(5, 6); 

    //using union by rank
    // if 3 and 7 same or not
    cout<<"disjoint using union by Rank:"<<endl;
    if(dsR.findUPar(3) == dsR.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    dsR.unionBySize(3, 7); 

    if(dsR.findUPar(3) == dsR.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    //using union by size
    // if 3 and 7 same or not
    cout<<"same disjoint using union by size:"<<endl;
    if(dsS.findUPar(3) == dsS.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    dsS.unionBySize(3, 7); 

    if(dsS.findUPar(3) == dsS.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}







