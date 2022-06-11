#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class MaxPriorityQueue {
    // data member
    vector<int> pq;

   public:
    MaxPriorityQueue() {

    }

    /**************** all the public functions are here ***************/

    void insert(int element) {
        //inserting
        pq.push_back(element);
        
        int childIndex=pq.size()-1;
        int parentIndex=(childIndex-1)/2;
        
        while(childIndex>0){
               if(pq[childIndex]>pq[parentIndex]){
            //swaping
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[childIndex];
            pq[childIndex]=temp;
        }
            else{
                break;
            }
            
            //updating indexes
            childIndex=parentIndex;
            parentIndex=(childIndex-1)/2;
            
            
        }
     
    }

    int getMax() {
       //checking if Max PQ is empty
        if(pq.size()==0){
            return INT_MIN;
        }
        
    return pq[0];
    }

    int removeMax() {
       //empty or not
           if(pq.size()==0){
            return INT_MIN;
        }
        //saving max element to return
        int ans=pq[0];
        //swaping
        pq[0]=pq[pq.size()-1];
        //popping
        pq.pop_back();
        
        //initializing indexes
        int parentIndex=0;
        int leftChildIndex=(2*parentIndex)+1;
        int rightChildIndex=(2*parentIndex)+2;
        int maxIndex=0;
        
        while(leftChildIndex<pq.size()){
            if(pq[leftChildIndex]>pq[maxIndex]){
                maxIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size() && pq[rightChildIndex]>pq[maxIndex]){
                maxIndex=rightChildIndex;
            }
            if(maxIndex==parentIndex){
                break;
            }
            
            //swaping
            int temp=pq[parentIndex];
            pq[parentIndex]=pq[maxIndex];
            pq[maxIndex]=temp;
            
            //updating
            parentIndex=maxIndex;
             leftChildIndex=(2*parentIndex)+1;
            rightChildIndex=(2*parentIndex)+2;
            
        }
        
        return ans;
        
    }

    int getSize() { 
      return pq.size();
    }

    bool isEmpty() {
       return pq.size()==0;
    }
};


int main(){
     cout<<"Implementation of Max Priority Queue"<<endl;
  MaxPriorityQueue pq;

  pq.insert(57);
  pq.insert(27);
  pq.insert(20);
  pq.insert(43);
  pq.insert(78);
  pq.insert(11);
  pq.insert(9);
  pq.insert(31);

 cout<<pq.removeMax();
 cout<<' '; 
 cout<<pq.removeMax(); 
  cout<<' '; 
 cout<<pq.removeMax();
  cout<<' ';  
 cout<<pq.removeMax();
  cout<<' ';  
 cout<<pq.removeMax(); 
  cout<<' '; 
 cout<<pq.removeMax();
  cout<<' ';  
 cout<<pq.removeMax();
  cout<<' ';  
cout<<pq.removeMax(); 
}