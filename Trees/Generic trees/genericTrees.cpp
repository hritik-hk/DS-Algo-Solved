//Generic trees complete

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

//Tree Node
template<typename T>
class TreeNode{
    public:
    T data;
    vector< TreeNode<T>*> children;

    TreeNode(T data){
         this->data=data;
    }
    
    //recursive destructor
    ~TreeNode(){
      for (int i = 0; i < children.size(); i++)
      {
        delete children[i];
      }
      
    }

};

//take input function using recursion
TreeNode<int>* takeInputRec(){
  
  int data;
  cout<<"enter data"<<endl;
  
  cin>>data;

  TreeNode<int>*root=new TreeNode<int>(data);
  cout<<"enter the num of children of "<<root->data<<endl;
  int num;
  cin>>num;
  for (int i = 0; i < num; i++)
  {
    TreeNode<int>*child=takeInputRec();
    root->children.push_back(child);

  }
  return root;
    
}

//printing Tree using recursion
template<typename T>
void printTree(TreeNode<T> *root){
  //here we don't require a base case beacause after printing the leaf nodes the function would return itself.
  //to handle edge case and this is not a base case
  if(root==NULL) return;

     //printing the root
     cout<<endl<<root->data<<": ";
    
     //printing root's children
     for (int i = 0; i < root->children.size(); i++)
     {
       cout<<root->children[i]->data<<' ';
     }
     


   for (int i = 0; i < root->children.size(); i++)
   {
     printTree(root->children[i]);
   }
   
}

//take input function using queue i.e take input levelwise.

TreeNode<int>* takeInput(){
  cout<<"Enter root data"<<endl;
  //queue of TreeNode
    queue<TreeNode<int>*> q;

    //integer data variable
    int data;
    cin>>data;

    //no tree
    if(data==-1) return NULL;

   TreeNode<int>*root=new TreeNode<int>(data);

     q.push(root);
    
    while(!q.empty()){

      cout<<"enter children of "<<q.front()->data<<endl;
      cin>>data;

   while(data!=-1){
     //making a new node
     TreeNode<int>*child=new TreeNode<int>(data);

     //pushing the child node to queue
     q.push(child);
     
     //connecting parent and children nodes using queue front()
     q.front()->children.push_back(child);

     //taking input for next node.
     cin>>data;

   }
    //poping out front element because it's work is done.
    q.pop();
    }

    //returning the root node
    return root;


}

//print level-wise
template<typename T>
void printLevelWise(TreeNode<T> *root){

    queue<TreeNode<T>*> pendingNodes;
     
     pendingNodes.push(root);

     while(!pendingNodes.empty()){
            cout<<pendingNodes.front()->data<<":";

           int i=0;
           int size=pendingNodes.front()->children.size();

            while(i<size){

              pendingNodes.push(pendingNodes.front()->children[i]);

              cout<<pendingNodes.front()->children[i]->data;

              if(i!=size-1) cout<<',';

              i++;
            }
            cout<<endl;

            pendingNodes.pop();
     }
}

//count total node
int countNodes(TreeNode<int>*root){
   int size=0;

  for (int i = 0; i < root->children.size(); i++)
  {
    int subsize=countNodes(root->children[i]);

    size=size+subsize;
  }

  return size+1;
  
}

//printing nodes at depth d
void NodeATdepth(TreeNode<int>*root,int depth){
  //edge case
  if(root==NULL) return;
  
    if(depth==0){
      cout<<root->data<<' ';
      return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
      NodeATdepth(root->children[i],depth-1);

    }
    
}

//counting total leaf nodes
int countLeafNodes(TreeNode<int>*root){

     int count=0;
    if(root->children.empty()){
         return 1;
    }
     for (int i = 0; i < root->children.size(); i++)
    {
      int subcount= countLeafNodes(root->children[i]);
            count=count+subcount;
    }

    return count;
}

//pre-order traversal/printing==root node-> left->right

void preorder(TreeNode<int>*root){

       //corner case
       if(root==NULL) return;

       cout<<root->data<<' ';

       for(int i=0;i<root->children.size();i++)
       {
         preorder(root->children[i]);
       }
}

//Post-Order Traveral/Printing

void PostOrder(TreeNode<int>*root){

  //corner case
  if(root==NULL) return;

  for(int i=0;i<root->children.size();i++)
       {
         PostOrder(root->children[i]);
       }

       cout<<root->data<<' ';
}

//In-Order Traversal/Printing

void InOrder(TreeNode<int>*root){
    
    //corner case
    if(root==NULL) return;

    bool printed=false;

    for(int i=0;i<root->children.size();i++)
       {
        InOrder(root->children[i]);
        
        if(printed==false){
          cout<<root->data<<' ';
          printed=true;
        }
       }

        if(root->children.empty())
        {
          cout<<root->data<<' ';
        }

     
}


int main(){

  //tree= 1 2 3 4 -1 5 -1 8 -1 10 -1 6 7 -1 9 -1 11 -1 -1 -1 -1 12 -1 13 21 -1 -1 -1
  //tree= 1 2 3 -1 4 5 -1 6 10 -1 7 8 -1 -1 -1 -1 -1 -1 

    TreeNode<int> *tree=takeInput();

           printLevelWise(tree);

           cout<<endl;

          //  cout<<"TOTAL NO. OF NODES ARE: "<<countNodes(tree);

          //  cout<<endl;

          //  cout<<"Node at depth d=2: ";
          //  NodeATdepth(tree,2);
          //   cout<<endl;
          //  cout<<"No. of leaf nodes: "<<countLeafNodes(tree)<<endl;

          //  cout<<"Pre-Order traversal/Printing- ";
          //  preorder(tree);
          //  cout<<endl;

          //  cout<<"Post-Order traversal/Printing- ";
          //  PostOrder(tree);
          //  cout<<endl;
          //  cout<<"In-Order traversal/Printing- ";
          //  InOrder(tree);
          //  cout<<endl;

           


                
                delete tree;

     
}
