/*Question->A thief wants to loot houses. He knows the amount of money in each house. 
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.*/

#include <bits/stdc++.h>
using namespace std;

//brute force-> recursive
//time-   space-
int maxMoneyLooted(int *arr, int n)
{
	//base case
     if(n==0) return 0;
    if(n==1) return arr[0];
    
    //loots first house
    int loots=maxMoneyLooted(arr+2,n-2)+arr[0];
    
    //doesn't loots
    int notLoots=maxMoneyLooted(arr+1,n-1);
    
    return max(loots,notLoots);
}


//memoization

int maxMoneyLooted(int *arr, int n, int*output)
{
	//base case
     if(n==0) return 0;
    if(n==1) return arr[0];
    
    
    //check if ans already exists
    if(output[n]!=-1) return output[n];
    //loots first house
    int loots=maxMoneyLooted(arr+2,n-2,output)+arr[0];
    
    //doesn't loots
    int notLoots=maxMoneyLooted(arr+1,n-1,output);
    
    output[n]=max(loots,notLoots);
    
    return output[n];
}


int maxMoneyLooted(int *arr, int n){
    int*output= new int[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=-1;
    }
    
    return maxMoneyLooted(arr,n,output);
}

//Tabulation
//time-> O(n), space ->O(n){array}
int maxMoneyLooted(int *arr, int n){
    
   int*dp=new int[n+1];
   dp[0]=0;
   dp[1]=arr[0];
    
    
    for(int i=2;i<n+1;i++){
        dp[i]=max(dp[i-1],dp[i-2]+arr[i-1]);
    }
    
    return dp[n];
    
}

//Tabulation -> Space Optimized
//time->O(n) , space->O(1)
int maxMoneyLooted(int *arr, int n){
    
  int curr, prev1=arr[0], prev2=0;
    
    
    for(int i=2;i<n+1;i++){
        curr=max(prev1,prev2+arr[i-1]);
        prev2=prev1;
        prev1=curr;
    }
    
    return prev1;
    
}

