#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<climits>

using namespace std;

class Node{
 public:
 int data;
 Node*next;

 Node(int data){
     this->data=data;
     next=NULL;
 }

};

//implementing queue using dynamic arrays

class QueueUsingArray {
	int *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

	public :
	QueueUsingArray(int s) {
		data = new int[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	// insert element
	void enqueue(int element) {
		if(size == capacity) {
			int *newData = new int[2 * capacity];
			int j = 0;
			for(int i = firstIndex; i < capacity; i++) {
				newData[j] = data[i];
				j++;
			}
			for(int i = 0; i < firstIndex; i++) {
				newData[j] = data[i];
				j++;
			}
			delete [] data;
			data = newData;
			firstIndex = 0;
			nextIndex = capacity;
			capacity *= 2;
			
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % capacity ;
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		size++;
	}
	
	int front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	int dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		int ans = data[firstIndex];
		firstIndex = (firstIndex + 1) % capacity;
		size--;
		if(size == 0) {
			firstIndex = -1;
			nextIndex = 0;
		}
		return ans;
	}

};

//implementing queue using Linkedlist


class Queue {
	// Define the data members
    Node*head;
	Node*tail;
    int size;
   public:
    Queue() {
		// Implement the Constructor
        head=NULL;
		tail=NULL;
		size=0;
	}

	int getSize() {
        return size;
	}

    bool isEmpty() {
        return size==0;
	}

    void enqueue(int data) {
        Node*newNode=new Node(data);
		 if(head==NULL){
			 head=newNode;
			 tail=newNode;
		 }

        else {
		 tail->next=newNode;
		 tail=newNode;
		}
         size++;
	}

    int dequeue() {
        if(size==0){
			return -1;
		}

		Node*temp=head;
		int value=head->data;
		head=head->next;
          delete temp;
         size--;
		  return value;
    }

    int front() {
        if(size==0){
			return -1;
		}

		return head->data;
    }
};

int main(){
	//queue using array
	cout<<"Implementing queue using array"<<endl;
	QueueUsingArray q1(6);
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);

	cout<<"popped:"<<q1.dequeue()<<endl;

	cout<<q1.front()<<endl;

	cout<<"size of queue: "<<q1.getSize()<<endl;

	cout<<"is queue empty: "<<q1.isEmpty();

	//queue using LinkedList
	cout<<"Implementing queue using linkedList"<<endl;
	Queue q;
	q.enqueue(50);
	q.enqueue(60);
	q.enqueue(70);
	q.enqueue(80);

	cout<<"popped:"<<q.dequeue()<<endl;

	cout<<q.front()<<endl;

	cout<<"size of queue: "<<q.getSize()<<endl;

	cout<<"is queue empty: "<<q.isEmpty();
}


