#include<bits/stdc++.h>
using namespace std;

//using BFS
    bool checkBipartiteBFS(int v,vector<int>adj[],vector<int>&color){
    queue<int> q;
    color[v]=0;
    q.push(v);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i:adj[node]){
           if(color[i]==-1){
            color[i]=1-color[node];
            q.push(i);
           }
           else if(color[i]==color[node]) return false;
        }
    }

 return true;

}


//using dfs
 bool checkBipartiteDFS(int sv,vector<int>adj[],vector<int>&color){
    if(color[sv]==-1) color[sv]=0;

    for(int i:adj[sv]){
        if(color[i]==-1){
            color[i]=1-color[sv];
            if(!checkBipartiteDFS(i,adj,color)) return false;
        }
        else if(color[i]==color[sv]) return false;
    }

    return true;

 }
   


bool checkBipartite(int v, vector<int>adj[]){
    //color array
    //assuming 1- based indexing
    //initialize with -1
    vector<int> vis(v+1,-1);

    for(int i=1;i<=v;i++){
        if(vis[i]==-1){
            if(!checkBipartiteBFS(i,adj,vis)) return false;
        }
    }
    return true;

}



