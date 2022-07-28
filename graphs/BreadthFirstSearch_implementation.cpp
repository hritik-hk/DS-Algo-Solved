#include<iostream>
#include<queue>
#include<vector>

using namespace std;


vector<int> bfs_list(int v, vector<int> adj[]){
    vector<int> ans;
    vector<int> visited(v+1,0); // 1-based indexing

   //because of the below for-loop, bfs code will work for disconnected graphs too
    for(int i=1;i<=v;i++){
        if(visited[i]==0){
             queue<int> pending;
          pending.push(i);
         visited[i]=1;
            while(!pending.empty()){
                int node=pending.front();
                ans.push_back(node);
                pending.pop();

                for(int &v:adj[node]){
                    if(visited[v]==0){
                    pending.push(v);
                    visited[v]=1;
                    }
                }


            }
        }
    }


return ans;

}

int main(){
    int v,e; //no. of vertices and edges
    cin>>v>>e;
    

    //adjaceny list 
    vector<int> adj[v+1]; 

    for(int i=0;i<e;i++){
        int u,v;   //adjacent vertices
        cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    } 
    

   vector<int> bfs= bfs_list(v,adj);

   for(int &i:bfs) cout<<i;


}