//BINARY TREES COMPLETE

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class BinaryTreeNode{
  public:
  T data;
  BinaryTreeNode<T>*left;
  BinaryTreeNode<T>*right;

  //constructor
  BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
  }

  //destructor
   ~BinaryTreeNode(){
     delete left;
     delete right;
   }

};

//takeInput -recursive

BinaryTreeNode<int>* takeInputRec(){
    int data;
    cout<<" Enter DATA:";
    cin>>data;
    if(data==-1) return NULL;

    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);

    cout<<"Enter -1 for no child, 1 for onyleft and 2 for onlyright and 3 for both for "<<root->data<<":";
    cin>>data;

    if(data==-1) return root;
       
    else if(data==1) {
      cout<<"left child of "<<root->data;
         BinaryTreeNode<int>*left=takeInputRec();
         root->left=left;
    }

    else if(data==2){
      cout<<"right child of "<<root->data;
           BinaryTreeNode<int>*right=takeInputRec();
           root->right=right;
    }

     else if(data==3){
       cout<<"left child of "<<root->data;
    BinaryTreeNode<int>*left=takeInputRec();
    root->left=left;
    cout<<"right child of "<<root->data;
    BinaryTreeNode<int>*right=takeInputRec();
    root->right=right;


     }

     return root;


}

//print recursively
template<typename T>
void printTreeRec(BinaryTreeNode<T>*root){
    //base case
     if(root==NULL) return;

     cout<<root->data<<": ";
     if(root->left!=NULL) cout<<'L'<<root->left->data;
     if(root->right!=NULL) cout<<" R"<<root->right->data;
     cout<<endl;

     printTreeRec(root->left);
     printTreeRec(root->right);
      
}

//take input levelwise - char
  BinaryTreeNode<char>* takeInputLevelWise_char(){
    //data variable for taking input
    char data;

    //queue for pushing in TreeNode pointers
     queue<BinaryTreeNode<char>*> pendingNodes;
    cout<<"Enter Root data: ";
    cin>>data;
    //returning NULL if root data is -1
    if(data=='0') return NULL;
    //creating BinaryTreeNode for root
    BinaryTreeNode<char>*root=new BinaryTreeNode<char>(data);

    //pushing node(here root) to queue
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
      // storing root address in front
        BinaryTreeNode<char>*front=pendingNodes.front();
        //popping front element of queue because we've saved it's address in front
        pendingNodes.pop();

        cout<<"enter left child of "<<front->data<<": ";
       cin>>data;
         //is data==-1 i.e we don't want left child hence we'll go on for right child
        if(data!='0'){
           BinaryTreeNode<char>*child=new BinaryTreeNode<char>(data);
           front->left=child;
           //pushing left child to queue
           pendingNodes.push(child);
        }
        
        cout<<"enter right child of "<<front->data<<": ";
          cin>>data;
        
        //is data==-1 i.e we don't want right child hence we'll go on for children for next front element of queue
        if(data!='0'){
           BinaryTreeNode<char>*child=new BinaryTreeNode<char>(data);
           front->right=child;
           //pushing right child to queue
            pendingNodes.push(child);
        }
        
    }
    
    //returning the root after we're done with taking input
    return root;
  }


//take input levelwise
  BinaryTreeNode<int>* takeInputLevelWise(){
    //data variable for taking input
    int data;

    //queue for pushing in TreeNode pointers
     queue<BinaryTreeNode<int>*> pendingNodes;
    cout<<"Enter Root data: ";
    cin>>data;
    //returning NULL if root data is -1
    if(data==-1) return NULL;
    //creating BinaryTreeNode for root
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);

    //pushing node(here root) to queue
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
      // storing root address in front
        BinaryTreeNode<int>*front=pendingNodes.front();
        //popping front element of queue because we've saved it's address in front
        pendingNodes.pop();

        cout<<"enter left child of "<<front->data<<": ";
       cin>>data;
         //is data==-1 i.e we don't want left child hence we'll go on for right child
        if(data!=-1){
           BinaryTreeNode<int>*child=new BinaryTreeNode<int>(data);
           front->left=child;
           //pushing left child to queue
           pendingNodes.push(child);
        }
        
        cout<<"enter right child of "<<front->data<<": ";
          cin>>data;
        
        //is data==-1 i.e we don't want right child hence we'll go on for children for next front element of queue
        if(data!=-1){
           BinaryTreeNode<int>*child=new BinaryTreeNode<int>(data);
           front->right=child;
           //pushing right child to queue
            pendingNodes.push(child);
        }
        
    }
    
    //returning the root after we're done with taking input
    return root;
  }

//printing Binary tree levelwise
 template<typename T>
  void printTreeLevelWise(BinaryTreeNode<T>* root){
        queue<BinaryTreeNode<T>*> pendingNodes;
        pendingNodes.push(root);
          
        while(!pendingNodes.empty()){
          BinaryTreeNode<T>*front=pendingNodes.front();
           pendingNodes.pop();
           cout<<front->data<<":";

          if(front->left!=NULL){
          cout<<"L:"<<front->left->data<<',';
           pendingNodes.push(front->left);
          }
          else cout<<"L:"<<-1<<',';

          if(front->right!=NULL){
           cout<<"R:"<<front->right->data;
           pendingNodes.push(front->right);
          }
          else cout<<"R:"<<-1;

            cout<<endl;
        }

  }

//count total Nodes
  template<typename T>
  int countNodes(BinaryTreeNode<T>*root){
    //base case + edge case
      if(root==NULL) return 0;

    //including root node
       int count=1;

       int leftCount=countNodes(root->left);
        count+=leftCount;

        int rightCount=countNodes(root->right);
        count+=rightCount;

        return count;

  }

  //preorder traversal== root node-> left->right
   template<typename T>
  void PreOrder(BinaryTreeNode<T>*root){
    //base case
      if(root==NULL) return;

      cout<<root->data<<' ';

      PreOrder(root->left);
      PreOrder(root->right);

}

  //post-order traversal== left->right->root node
   template<typename T>
  void PostOrder(BinaryTreeNode<T>*root){
    //base case
      if(root==NULL) return;

      PostOrder(root->left);
      PostOrder(root->right);

      cout<<root->data<<' ';
}

//In-order traversal== left->root->right
   template<typename T>
  void InOrder(BinaryTreeNode<T>*root){
    //base case
      if(root==NULL) return;

      InOrder(root->left);

      cout<<root->data<<' ';

      InOrder(root->right);
}

//find height
int getHeight(BinaryTreeNode<int>*root){
  int height=-1;
  //edge case
  if(root==NULL) return height;

  // int leftHeight=getHeight(root->left);
  // int rightHeight=getHeight(root->right);

  // height=max(leftHeight,rightHeight);

  // return height+1;


  return max(1+getHeight(root->left),1+getHeight(root->right));
}

//find diameter of binary tree 
//time complexity- O(n*h)  -- h->height of binary tree
int getDiameter(BinaryTreeNode<int>*root){
  int diameter=-1;
  //edge case
  if(root==NULL) return diameter;

  int leftHeight=getHeight(root->left);
  int rightHeight=getHeight(root->right);

  int d1=leftHeight+rightHeight;
  int d2=getDiameter(root->left);
  int d3=getDiameter(root->right);
  diameter=max(d1,max(d2,d3));
  return diameter;
}

//get diameter better approah
//in c++ stl we have an inbuilt pair template two data memebers first and second
//hence we will here take, firstd==height and second==diameter .
//to delare object of pair template- pair<datatype,datatype>

//this function returns both height and diameter of the given binary tree

 pair<int,int> getHeightDiameter(BinaryTreeNode<int>*root){
      
      pair<int,int> ans;
      ans.first=-1;
      ans.second=-1;
       
       //base case
      if(root==NULL) return ans;

      //induction hypothesis

      pair<int,int> leftans=getHeightDiameter(root->left);

      pair<int,int> rightans=getHeightDiameter(root->right);
     
     //induction step

     int lHeight=leftans.first;
     int rHeight=rightans.first;
     int lDiameter=leftans.second;
     int rDiameter=rightans.second;

    int height= 1+ max(lHeight,rHeight);
   
    int diameter= max(2+lHeight+rHeight,max(lDiameter,rDiameter));

    ans.first=height;
    ans.second=diameter;

    return ans;
     
}



int main(){
   
  //  BinaryTreeNode<int>*root=new BinaryTreeNode<int>(11);
  //   BinaryTreeNode<int>*node1=new BinaryTreeNode<int>(12);
  //    BinaryTreeNode<int>*node2=new BinaryTreeNode<int>(7);
  //     BinaryTreeNode<int>*node3=new BinaryTreeNode<int>(8);
  //      BinaryTreeNode<int>*node4=new BinaryTreeNode<int>(4);
  //       BinaryTreeNode<int>*node5=new BinaryTreeNode<int>(5);

  //       root->left=node1;
  //       root->right=node2;

  //       node1->left=node3;
  //       node1->right=node4;
  //       node2->right=node5;

  //Tree Input== 11 7 4 20 35 47 -1 -1 -1 42 -1 15 21 -1 -1 -1 -1 8 -1 -1 -1
  //Tree Input== A B C D E 0 F 0 0 H 0 K G 0 0 0 0 0 0
      
      //taking input levelwise
     BinaryTreeNode<int>*root=takeInputLevelWise();
     cout<<endl;

       //printing levelwise
        // printTreeLevelWise(root);
        // cout<<endl;

        //Pre-Order printing
        // PreOrder(root);

        //Post-Order Printing
          // PostOrder(root);

          //In-Order Printing
            // InOrder(root);

        // //total number of nodes
        // cout<<"Total Nodes: "<<countNodes(root)<<endl;

        pair<int,int> p=getHeightDiameter(root);

        cout<<"height of the binary tree: "<<p.first<<endl;
        cout<<"diameter of the binary tree: "<<p.second<<endl;



        delete root;

cout<<endl;

}
