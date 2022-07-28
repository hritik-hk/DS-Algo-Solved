//Level Order Traversal using Queue.
//Level Order is also known as Breadth first Search(BFS).
//time-O(n), space-O(n)

#include<bits/stdc++.h>
using namespace std;

//level order traversal using Queue
 vector<vector<int>> levelOrder(TreeNode* root) {
        
        //edge case
        if(root==NULL) return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> pendingNodes;
        
        pendingNodes.push(root);
        
        while(!pendingNodes.empty()){
            
            int size=pendingNodes.size();
            
            vector<int> level;  //for storing current level element;
            
            while(size){
                root=pendingNodes.front();
                pendingNodes.pop();
                
                //check left
                if(root->left!=NULL) pendingNodes.push(root->left);
                
                //check right
                if(root->right!=NULL) pendingNodes.push(root->right);
                
                level.push_back(root->val);
                size--;
            }
            
            ans.push_back(level);
            
        }
        
        return ans;
        
    }


    //level order traversal using recursion
    //time -O(n^2) space-O(n)
    
    int height(TreeNode*node){
    if(node==NULL) return -1;
    
    return 1+ max(height(node->left),height(node->right));
}

vector<int> printLevel(TreeNode*node,int level){
    
  
    
    if(node==NULL) return {};
    
    if(level==0) return {node->val};
    
    
        vector<int> left=printLevel(node->left,level-1);
        
        vector<int> right= printLevel(node->right,level-1);
        
        vector<int> ans;
        for(int i:left) ans.push_back(i);
          for(int i:right) ans.push_back(i);
          
          return ans;
        
    
}

 vector<vector<int>> levelOrder(TreeNode* node) {
          vector<vector<int>> ans;
        if(node==NULL) return ans;
        
    //height of binary tree
    int h=height(node);
  
  //print from level-0 to level-height
  for(int level=0;level<=h;level++ ){
      
      ans.push_back(printLevel(node,level));
      
  }
  
  return ans;
        
    }
