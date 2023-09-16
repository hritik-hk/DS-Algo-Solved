#include<bits/stdc++.h>
using namespace std;


//cycle detection using bfs
//given vertices and adjacency list {1-based indexing}

    bool isCycleBFS(int s,int V,vector<int> adj[],vector<int> &visited){

        // Create a queue for BFS
       queue<pair<int,int >>q;
       visited[s]=true;
        q.push({s,-1});

       while(!q.empty()){
            int node=q.front().first;
            int prev=q.front().second;
           q.pop();

            for(auto it: adj[node]){
               if(!visited[it]){
                   visited[it]=true;
                    q.push({it,node});
         }
         else if(prev!=it) return true;
           }
       }
      

    return false;

    }
                




   bool isCycleBFS(int v,vector<int>adj[]){
       vector<int> vis(v+1,0);

        for(int i=1;i<=v;i++){
            if(!vis[i]){
               if(isCycleBFS(i,v,adj,vis))return true;
           }
        }
        return false;
        }


//cycle detection using DFS
//given vertices and adjacency list {1-based indexing}

bool isCycleDFS(int sv,int prev,vector<int>adj[], vector<int> &vis ){
       vis[sv]=1;

       for(int i:adj[sv]){
        if(!vis[i]){ 
            if(isCycleDFS(i,sv,adj,vis)) return true;
        }
        else if(i!=prev) return true;
       }

       return false;

}


bool isCycleDFS(int v,vector<int>adj[]){

  vector<int> vis(v+1,0);

  for(int i=1;i<=v;i++){
    if(!vis[i]){
        if(isCycleDFS(i,-1,adj,vis)) return true;
    }

  }

}




int main(){

    

}