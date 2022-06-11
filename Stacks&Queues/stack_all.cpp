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

//stack using dynamic array
class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;	

	public :

	StackUsingArray() {
		data = new int[4];
		nextIndex = 0;
		capacity = 4;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
	return nextIndex == 0;
	}

	// insert element
	void push(int element) {
		if(nextIndex == capacity) {
			int *newData = new int[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	int pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex - 1];
	}
};



//stack using LinkedList

class Stack {
	//  data members
    Node*head;
    int size;
   public:
    Stack() {
        //  Constructor
        head=NULL;
        size=0;
    }

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(head==NULL) return true;
        else return false;
    }

    void push(int element) {
        // Implement the push() function
        Node*temp=new Node(element);
        if(head==NULL){
            head=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }

    int pop() {
        // Implement the pop() function
        if(isEmpty()){
            return -1;  
        }
        int ans=head->data;
        Node*temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

    int top() {
        // Implement the top() function
        if(isEmpty()){
            return -1;  
        }
        return head->data;
    }
};

int main(){

    //stack using array
     StackUsingArray s1;
     s1.push(10);
     s1.push(20);
     s1.push(30);
    s1.push(40);
    s1.push(50);

    cout<<"last element popped: "<<s1.pop()<<endl;

    cout<<"top element: "<<s1.top()<<endl;
    cout<<"size of stack: "<<s1.size()<<endl;
    cout<<"is stack empty: "<<s1.isEmpty()<<endl;

    //stack using linkedlist
    Stack s2;
     s2.push(60);
     s2.push(70);
     s2.push(80);
    s2.push(90);
    s2.push(100);

    cout<<"last element popped: "<<s2.pop()<<endl;

    cout<<"top element: "<<s2.top()<<endl;
    cout<<"size of stack: "<<s2.getSize()<<endl;
    cout<<"is stack empty: "<<s2.isEmpty()<<endl;
   
    
    
    
}
