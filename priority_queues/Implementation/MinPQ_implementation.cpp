#include <iostream>
#include<vector>

using namespace std;



//implementing min priority queue
class MinPriorityQueue{
    // using vector for storing the priority queue
    vector<int> pq;


    public:
    //constructor-> we don't have to do anything here
    MinPriorityQueue(){
    }
// returns if the priority queue is empty or not
    bool isEmpty(){
        return pq.size()==0;
    }

  //return the number of elment in the priority queue
    int getSize(){
        return pq.size();
    }

  //
    int getMin(){
      if(pq.size()==0){
        return -1;
      }
      else{
       return pq[0];
      }
      
    }

    void insert(int data){
      //inserting at the last of queue.
      pq.push_back(data);

      int childIndex=(pq.size())-1;

      while(childIndex>0){
        int parentIndex=(childIndex-1)/2;

        if(pq[childIndex]<pq[parentIndex]){
          //swaping
          int temp=pq[parentIndex];
          pq[parentIndex]=pq[childIndex];
          pq[childIndex]=temp;
        }
        else{
          break;
        }
        
        childIndex=parentIndex;

      }
    
    }

    int removeMin(){
      //if priority queue is empty
           if (isEmpty()) {
            return 0;
        }
        //saving ans
        int ans=pq[0];
        
        //deleting and swaping
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        //maintaining indexs
        int parentIndex=0;
        int leftChild=(2*parentIndex)+1;
        int rightChild=(2*parentIndex)+2;
        int minIndex=0;
        
        while(leftChild<pq.size()){
             if(pq[minIndex]>pq[leftChild]){
                minIndex=leftChild;
            }
            if(rightChild<pq.size() && pq[minIndex]>pq[rightChild]){
                minIndex=rightChild;
            }
            if(minIndex==parentIndex){
                break;
            }
            
            //swaping
          int temp=pq[parentIndex];
            pq[parentIndex]=pq[minIndex];
            pq[minIndex]=temp;
          
            
            //updating left and right child
            parentIndex=minIndex;
        leftChild=(2*parentIndex)+1;
        rightChild=(2*parentIndex)+2;
            
        }
            
         return ans;   
            
    }


};


int main(){
  cout<<"Implementation of Min Priority Queue"<<endl;
  MinPriorityQueue pq;

  pq.insert(57);
  pq.insert(27);
  pq.insert(20);
  pq.insert(43);
  pq.insert(78);
  pq.insert(11);
  pq.insert(9);
  pq.insert(31);

 cout<<pq.removeMin();
 cout<<' '; 
 cout<<pq.removeMin(); 
  cout<<' '; 
 cout<<pq.removeMin();
  cout<<' ';  
 cout<<pq.removeMin();
  cout<<' ';  
 cout<<pq.removeMin(); 
  cout<<' '; 
 cout<<pq.removeMin();
  cout<<' ';  
 cout<<pq.removeMin();
  cout<<' ';  
cout<<pq.removeMin(); 
}