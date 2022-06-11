#include<iostream>
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

Node* takeInput(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node*newNode=new Node(data);
      if(head==NULL){
          head=newNode;
          tail=newNode;
      }
      else{
        tail->next=newNode;
        tail=newNode;
      }
      cin>>data;
      

    }
    return head;
}

void print(Node*head){
   Node*temp=head;
   while(temp!=NULL){
      cout<<(temp->data)<<' ';
      temp=temp->next;
   }  
   cout<<endl;
}

Node* insertNode(Node*head,int data,int position){
    Node*newNode=new Node(data);
    Node*temp=head;
    int j=0;
    if(position==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    
    while(temp!=NULL){
        if(j==(position-1)){
           Node*store=temp->next;
           temp->next=newNode;
           newNode->next=store;
           
        }
        temp=temp->next;
        j++;
    }
    
    return head;
}
Node *deleteNode(Node *head, int pos)
{
       Node*temp=head;
    int count=0;
    if(pos==0){
        Node*remove=head;
        head=head->next;
        delete remove;
        return head;   
    }
    
    while(temp!=NULL && count<pos-1){
          temp=temp->next;
        count++;
    }
        if(temp!=NULL && temp->next!=NULL){
        Node*remove=temp->next;
        temp->next=remove->next;
        delete remove;
    }
    
    return head;
    
    
}

Node* insertRec(Node*head,int data,int pos){
     
     Node*newNode=new Node(data);
     //base case
     if(head==NULL){
         return head;
     }
     
     if(head!=NULL && pos==0){
       newNode->next=head;
       head=newNode;
       return head;
     }
     
   Node*temp=insertRec(head->next,data,pos-1);
     head->next=temp;
     return head;
}

Node *deleteRec(Node *head, int pos){
      //base case
      if(head==NULL){
          return head;
      }

      if(pos==0){
          Node*remove=head;
          head=head->next;
          delete remove;
          return head;
      }
      Node*temp=deleteRec(head->next,pos-1);
             head->next=temp;
      return head;
}

Node *appendLastNToFirst(Node *head, int n)
{
    Node*temp1=head;
    int length=1;
    while(temp1->next!=NULL){
        length++;
        temp1=temp1->next;
    }
    int j=1;
    Node*temp2=head;
    while(j<(length-n)){
      j++;
        
        temp2=temp2->next;
    }
    
    temp1->next=head;
    head=temp2->next;
    temp2->next=NULL;
    return head;
}

Node *reverseLinkedList(Node *head) {
    //corner cases
    if(head==NULL || head->next==NULL){
        return head;
    }
     Node*prev=NULL;
    Node*current=head;
    Node*next=NULL;
     
    while(current!=NULL){
         next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        
    }
    
    return prev;
    
}


Node *reverseLinkedListRec(Node *head)
{
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node*smallHead=reverseLinkedListRec(head->next);
      head->next->next=head;
     head->next=NULL;
    return smallHead;
}


Node*merge(Node*head1,Node*head2)
{   
    //handling the corner cases
    if(head1==NULL || head2==NULL){
        if(head1==NULL && head2==NULL){
              return head1;
        }
        else if(head1==NULL){
            return head2;
        }
        else{
            return head1;
        }
    }



    Node*fHead=NULL;
    Node*fTail=NULL;

    while(head1!=NULL && head2!=NULL){
       if( (head1->data) <= (head2->data) ){
           if(fHead==NULL){
           fHead=head1;
           fTail=head1;
           head1=head1->next;

          }
           else{
           fTail->next=head1;
           fTail=head1;
           head1=head1->next;
           }
       }


        else if(head2->data<head1->data){
              if(fHead==NULL){
           fHead=head2;
           fTail=head2;
           head2=head2->next;

             }
           else{
           fTail->next=head2;
           fTail=head2;
           head2=head2->next;
           }
       }

    }

    if(head1!=NULL){
        fTail->next=head1;
    }
    else{
        fTail->next=head2;
    }

    return fHead;
}

// Node *reverseLinkedListRec(Node *head) {
//     if(head == NULL || head -> next == NULL)
//         return head;
//     Node* smallhead = reverseLinkedListRec(head->next);
//     head -> next -> next = head;
//     head -> next = NULL;
//     return smallhead;
// }

Node *evenAfterOdd(Node *head)
{  
    // handles - when LL of size zero or one
    if(head==NULL || head->next==NULL){
    return head;
            }

    Node*OH=NULL;
    Node*OT=NULL;
    Node*EH=NULL;
    Node*ET=NULL;
    Node*count=head;
    
    while(count!=NULL){
        if((count->data)%2==0 ){
            if(EH==NULL){
                EH=count;
                ET=count;
            }
            else{
                ET->next=count;
                ET=count;
            }
        }
        
         if((count->data)%2!=0 ){
            if(OH==NULL){
                OH=count;
                OT=count;
            }
            else{
                OT->next=count;
                OT=count;
            }
        }
        count=count->next;
    }
    //handling cases where LL is complete odd or even.
    if(EH==NULL) {
       OT->next==NULL;
       return OH;
    }
    
    if(OH==NULL){
         ET->next==NULL;
       return EH;
    }

     OT->next=EH;
    ET->next=NULL;
 
    return OH;
}

//application of 2 pointers approach/
int LastKth(Node*head, int k){
    Node*slow=head;
    Node*fast=head;

  //moving the fast pointer k node ahead.

   for (int i = 0; i < k; i++)
   {
       fast=fast->next;
   }

  //the slow pointer will stop kth node from last
   while(fast!=NULL){
     slow=slow->next;
     fast=fast->next;
   }

   return slow->data;
   
}

int main(){
    cout<<"enter the elements"<<endl;
  Node*head=  takeInput();
  print(head);
  cout<<endl;
//   cout<<"enter the elements of second LL"<<endl;
//   Node*head2=  takeInput();
//   print(head);
//   cout<<endl;
  int data,position;
//   cout<<"enter data to be inserted: ";
//   cin>>data;
//   cout<<"enter the position: ";
//   cin>>position;
//   head=insertRec(head,data,position);
//   print(head);
//    cout<<"enter the position to be deleted: ";
//    cin>>position;
//    head=deleteRec(head,position);
//    print(head);

// Node*ans=appendLastNToFirst(head,3);
// print(ans);
// Node*newHead=evenAfterOdd(head);

// print(newHead);

// Node*mergedHead=merge(head,head2);
// print(mergedHead);



cout<<"enter the k: ";
cin>>data;

cout<<"Kth element from last is: "<<LastKth(head,data);

}




