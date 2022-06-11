#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
  
  priority_queue<int> pq;

  pq.push(20);
  pq.push(67);
  pq.push(23);
  pq.push(54);
  pq.push(36);
  pq.push(2);
  pq.push(37);
  pq.push(100);

  cout<<pq.size()<<endl;

  while(!pq.empty()){
      cout<<pq.top()<<' ';
      pq.pop();
  }
  
}
