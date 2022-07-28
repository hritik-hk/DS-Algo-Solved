/*
Input=> n vertices=> 0,1,2...n-1
  edges=> no. of edges and specify for eg. 1 2 meaning theres an edge btw 1 and 2 nodes
  
*/
#include<iostream>
#include<vector>
using namespace std;



//using Adjacency List
//adj[]->adj list, sv=starting vertex for dfs
void dfs_list(vector<int> adj[], int sv,vector<bool> &visited, vector<int>&dfs){   
 
   
      dfs.push_back(sv);
      visited[sv]=true;

      for(int&v: adj[sv]){
       if(!visited[v]) dfs_list(adj,v,visited,dfs);
      }
     
  
}






//using Adjacency Matrix
void printDFS(vector<vector<bool>> &edgesMatrix,int vertices,int startVertex, vector<bool>& visited){
    cout<<startVertex<<' ';
    visited[startVertex]=true;

    for(int i=0;i<vertices;i++){
        if(startVertex==i) continue;

        if(edgesMatrix[startVertex][i]){
            if(visited[i]) continue;
        printDFS(edgesMatrix,vertices,i,visited);
        }
    }

}



int main(){
    //using Adjacency List
    int v,e; //no. of vertices and edges
    cin>>v>>e;
    
    //visted node array
vector<bool>visited(v+1,false);

    //adjaceny list 
    vector<int> adj[v+1]; 

    for(int i=0;i<e;i++){
        int u,v;   //adjacent vertices
        cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    } 

    vector<int> res;
    
    for(int i=1;i<v;i++){
      if(!visited[i]) dfs_list(adj,i,visited,res);
    }

    for(int &i:res) cout<<i;



//  //using  adjacency matrix 
//  vector<vector<bool>> edgesMatrix(v,vector<bool>(v,false));

// //filling matrix
// for(int i=0;i<e;i++){
// int f,s;  //first node and second node
// cin>>f>>s;
// edgesMatrix[f][s]=true;
// }

//   printDFS(edgesMatrix,v,0,visited);






}