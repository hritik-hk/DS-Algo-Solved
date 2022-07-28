/*
Covers-> preorder, postorder,inorder and level Order.
tip-> watch striver's video to revise if your can't remember anything.
*/



#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
 
 TreeNode(int val){
    this->val=val;
    left=NULL;
    right=NULL;
 }

};


// postorder Traversal using two stack
    vector<int> postorderTraversal(TreeNode* root) {
        
        //edge case
        if(root==NULL) return {};
        
        vector<int> postorder;
        
        stack<TreeNode*> s1,s2;
        
        s1.push(root);
        
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL) s1.push(root->left);
            
            if(root->right!=NULL) s1.push(root->right);
        }
        
        
        while(!s2.empty()){
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        
        return postorder;
        
    }


//Preorder traversal using Stack
//Time-O(n), space-O(n) due to stack space in worst case not due to preorder vector.
        vector<int> preorderTraversal(TreeNode* root) {
        
        //edge case
        if(root==NULL) return {};
        
        vector<int> preorder;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            root=s.top();
            s.pop();
            preorder.push_back(root->val);
            
            if(root->right!=NULL) s.push(root->right);
             if(root->left!=NULL) s.push(root->left); 
        }
        
        return preorder;
           
    }

//Inorder traversal using Stack.
//Time-O(n), space-> O(n)-> incase of skewed left tree.
   vector<int> inorderTraversal(TreeNode* root) {
     //edge case
        if(root==NULL) return {};
        
        vector<int> inorder;
        
        stack<TreeNode*> s;
        
        while(true){
            
            if(root==NULL){
                if(s.empty()) break;
                root=s.top();
                s.pop();
                inorder.push_back(root->val);
                root=root->right;
            }
            else{
                s.push(root);
                root=root->left;
            }
            
            

        }
        
        return inorder;
                
    }

