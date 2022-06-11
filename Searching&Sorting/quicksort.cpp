#include<iostream>

using namespace std;

int partition(int arr[], int si,int ei){
       int count=0; //no. of elements before pivot and also pivot index
   for(int i=1; i<=ei ;i++){
      if(arr[i]<=arr[0]){
        count++;
      }
    }
    //swaping pivot to it's right position
    int temp=arr[count];
    arr[count]=arr[0];
    arr[0]=temp;
   
    /*
    moving all elements less than or equal to pivot to left of it and 
    elements greater than it to right of it
    */
    int i=si,j=ei;
    while(i != count && j != count){
    if(arr[i]<=arr[count]){
        i++;
    }
    else if(arr[j]>arr[count]){
        j--;
    }
    else{
        //swap
        int swap=arr[i];
        arr[i]=arr[j];
        arr[j]=swap;
        i++;
        j--;
    }
    }
    
    return count;
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    
    
    //start, end, pivot index
    int si=0, ei=size-1;
    
    //base case
    if(si>=ei){
        return;
    }
    
    //calling the partition functionn
    //taking zeroth index element as pivot
    int pi=partition(input,si,ei);
    //calling qs() on the two parts
    
    quickSort(input,pi);
    quickSort(input+pi+1,ei-pi);
    

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}