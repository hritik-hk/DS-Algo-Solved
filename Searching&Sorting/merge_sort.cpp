#include <iostream>
using namespace std;

void merge_sorted_arrays(int arr1[],int arr2[],int size1, int size2, int size){
    //creating an array in which we'll store sorted array
    int merged[size];
    
    
     int i=0,j=0,k=0;
     
       while(i<(size1) && j<(size2)){
        if(arr1[i]<=arr2[j]){
          merged[k]=arr1[i];
          i++;
        }
        else{
          merged[k]=arr2[j];
          j++;
        }
        k++;
       }
        
     while(i<(size1) || j<(size2)){
        if(i<(size1)){
          merged[k]=arr1[i];
          k++;
          i++;
        }
        else{
             merged[k]=arr2[j];
          k++;
          j++;
        } 
       } 
    
    for(int h=0;h<size;h++){
        arr1[h]=merged[h];
        
    }
}



void mergeSort(int input[], int size){
	//starting(si),mid(m) and ending index(ei)
    int si=0,ei=size-1;
    int mid=(si+ei)/2;
    
    //base case
    if(si>=ei){
        return;
    }
    
    //calling mergeSort() on the two halves and letting recursion sort it.
    /*
    if we compare it to PMI... we basically using extented PMI... that is function 
    we're assuming fucntion is true / working for values less than n or size less than 
    given therefore working for the two eual halves.
    */
    
    mergeSort(input,mid+1);  //first half
    mergeSort(input+mid+1,ei-mid); //second half
    
    //calling merge_sorted_arrays to merge the two sorted array.
    merge_sorted_arrays(input,input+mid+1,mid+1,ei-mid,size);
        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}


