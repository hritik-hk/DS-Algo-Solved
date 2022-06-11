/*
Problem-> Find nth fibonacci number, take  fib(0) = 0 and fib(1) = 1.
*/

#include<iostream>
using namespace std;

//brute force- recursive
// time=O(2^n), space=O(2^n)
int fib1(int num){
    //edge case->negative numbers
    if(num<0) return -1;

    //base case
    if(num<=1){
        return num;
    }

    return fib1(num-1)+ fib1(num-2);
}


//memoization
//time= O(n), space= O(n)
int fib2_helper(int num, int*arr){
       //edge case->negative numbers
    if(num<0) return -1;

    //base case
    if(num<=1){
        return num;
    }

    //check if ans already exists
    if(arr[num]!=-1){
        return arr[num];
    }
     
     arr[num]=fib1(num-1)+ fib1(num-2);
    return arr[num] ;

}
int fib2(int n){
 //using array to save result to prevent overlapping calls
   int*arr=new int[n+1];
   //initializing
   for(int i=0;i<n+1;i++){
     arr[i]=-1;
   }
  return fib2_helper(n,arr);
}

//using dynamic Programming
//time=O(n) , space= O(1)
int fib3(int num){
 
 int a=0, b=1,c;
 if(num<=1) return num;

 for(int i=2;i<num+1;i++){
   c=a+b;
   a=b;
   b=c;
 }

return c;
}


int main(){
    int num;
    cin>>num;
     cout<<fib3(num);
}