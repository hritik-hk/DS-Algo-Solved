#include<bits/stdc++.h>
using namespace std;
 
 bool checkCycleDFS(int sv, vector<int> adj[],vector<int>&vis, vector<int>&dfsVis){
    vis[sv]=1;
    dfsVis[sv]=1;
    for(auto i: adj[sv]){
        if(vis[i]==0){
            if(checkCycleDFS(i,adj,vis,dfsVis)) return true;
        }
        else if(dfsVis[i]) return true;
    }

   dfsVis[sv]=0;
   return false;

 }

 bool checkCycle(int v, vector<int> adj[]){
   vector<int> vis(v+1,0);
   vector<int> dfsVis(v+1,0);

   for(int i=1;i<=v;i++){
    if(!vis[i]){
       if(checkCycleDFS(i,adj,vis,dfsVis)) return true;
    }
   }

   return false;
 }

 int main(){

 }