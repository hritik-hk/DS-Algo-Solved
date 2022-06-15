//Longest Possible Subsequence

#include<bits/stdc++.h>
using namespace std;

//brute force- recursive
//time-O(2^n) space-O(2^n)
int lcs(string s, string t){
  //base case
    if(s.length()==0 || t.length()==0){
    return 0;
  }

if(s[0]==t[0]){
    int x=lcs(s.substr(1),t.substr(1));
    return 1+x;
}

//discarding s[0] i.e assuming it would not come the ans
int a=lcs(s.substr(1),t);

//discarding t[0]
int b=lcs(s,t.substr(1));

//discarding both s[0] and t[0]
int c=lcs(s.substr(1),t.substr(1));

int ans=max(a,max(b,c));
return ans;


}


//memoization
//time-O(m*n) space-O(m*n) {but matrix+ call stack}
  int lcs(string s, string t,int **output){
        int m = s.size();
    	int n = t.size();

  //base case
  if(s.length()==0 || t.length()==0){
    return 0;
  }
  
  // Check if ans already exists
	if(output[m][n] != -1) {
		return output[m][n];
	}

if(s[0]==t[0]){
    int x=lcs(s.substr(1),t.substr(1),output);
    output[m][n]=x+1;
    return 1+x;
}

//discarding s[0] i.e assuming it would not come the ans
int a=lcs(s.substr(1),t,output);

//discarding t[0]
int b=lcs(s,t.substr(1),output);

//discarding both s[0] and t[0] , this call is reduntant
int c=lcs(s.substr(1),t.substr(1),output);

int ans=max(a,max(b,c));
// Save your calculation
	output[m][n] = ans;
return ans;


}

int lcs_mem(string s, string t){
  int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}
        
	return lcs(s, t, output);
}



//DP- tabulation
//time-O(m*n) space-O(m*n) {only matrix}
int lcs_dp(string s, string t){
   int m = s.size();
	int n = t.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

  //filling first row
  for(int j=0;j<n+1;j++){
    output[0][j]=0;
  }

  //filling first col
  for(int i=0;i<m+1;i++){
    output[i][0]=0;
  }

  //filling rest of ouput

  for(int i=1;i<m+1;i++){

    for(int j=1;j<n+1;j++){

      string s1=s.substr(m-i);
      string t1=t.substr(n-j);

      if(s1[0]==t1[0]){
        output[i][j]=1+output[i-1][j-1];
      }

      else{
        // below code will also work as c is reduntant
           // output[i][j]=max( output[i-1][j], output[i][j-1]);
         int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
      }
    }
  }
   
   return output[m][n];
}

int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;

    cout<<lcs_dp(s,t)<<endl;

    cout<<lcs_mem(s,t)<<endl;

    cout<<lcs(s,t)<<endl;

  

}