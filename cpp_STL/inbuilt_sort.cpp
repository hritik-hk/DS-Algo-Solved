#include <iostream>
#include<vector>
#include <algorithm>

bool compare_decending(int a, int b){
    return a>b;
}

using namespace std;

int main()
{
    vector<int> v={2,4,5,3,7,8,9};
    
      sort(v.begin(),v.end());
      
      for(int i:v) cout<<i<<' ';
      
      cout<<endl;
    
    sort(v.begin(),v.end(),compare_decending);
    
      for(int i:v) cout<<i<<' ';
    

}