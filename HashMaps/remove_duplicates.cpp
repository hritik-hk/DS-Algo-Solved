/*
Input->Given Input Array.

Output-> Return a vector containing non duplicates elements occurring in the same order as in the array.

TIME COMPLEXITY-> O(n)
SPACE COMPLEXITY-> O(n)

*/


#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> removeDuplicates(int*arr,int size){
    vector<int> v;
    unordered_map<int,bool> ourMap;

    for(int i=0;i<size;i++){
     
     if(ourMap.count(arr[i])==0){
         v.push_back(arr[i]);
         ourMap[arr[i]]=true;
     }

    }

    return v;

}

int main(){

int arr[] = { 1, 2, 5, 1, 7, 2, 4, 2};

int arrLen = sizeof(arr)/sizeof(arr[0]);

vector<int> v1=removeDuplicates(arr,arrLen);

for(auto i: v1){
    cout<<i<<' ';
}
cout<<endl;
    
}