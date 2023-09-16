// Frog Jump with K Distance
//problem link- https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>

/*
recursion
TC-exponential, SC-exponential
memoization
TC-O()
*/

using namespace std;

int helper(vector<int>&height,int n,int k,vector<int>&dp){
    //base case
    if(n==0) return 0;
    
    //save
    if(dp[n]!=-1) return dp[n];
    
    int mi=INT_MAX;
    for(int i=1;i<=k;i++){
        int a=INT_MAX;
        if(i<=n) a=helper(height,n-i,k,dp)+abs(height[n-i]-height[n]);
        
        mi=min(a,mi);
    }
    
    return dp[n]=mi;
}


int frogJump(vector<int>&height, int n,int k){
    vector<int>dp(n,-1);
    //memoization
    // return helper(height,n-1,k,dp);

    //tabulation
    dp[0]=0;

    for(int i=1;i<n;i++){
        int mi=INT_MAX;
        for(int j=1;j<=k;j++){
            int sub=INT_MAX;
            if(j<=n) sub=dp[j-i]+abs(height[i]-height[j]);

            mi=min(sub,mi);
        }
        dp[i]=mi;
    }

    return dp[n-1];
}

int main()
{

    
    int n,k;
    cin>>n>>k;
   vector<int>h(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        h[i]=a;
    }

    cout<< frogJump(h,n,k);
   
}