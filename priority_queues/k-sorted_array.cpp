/*
K-sorted Array or  Near sorted array

*/

#include<bits/stdc++.h>
using namespace std;


// time => (n+k)log(k) , for avg case n>>k then O(n)
void kSortedArray(vector<int>& arr, int k){

priority_queue<int> pq;
//pushing first k elements in the priority queue
for(int i=0;i<k;i++) pq.push(arr[i]);

//sorting
//we'll maintain idx where we'll were inserted numbers in sorted order
//we'll run a loop that will run from i=k to i<arr.size 

int idx=0;
for(int i=k;i<arr.size();i++){
    arr[idx]=pq.top();
  pq.pop();
  pq.push(arr[i]);
  idx++;
}

while(!pq.empty()){
     arr[idx]=pq.top();
     pq.pop();
     idx++;
}
}

int main(){

vector<int> v={12,15,7,4,9};
int k=3;
kSortedArray(v,k);
for(int i:v) cout<<i<<' ';
cout<<endl;

}
  