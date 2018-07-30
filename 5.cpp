#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;
 
typedef struct TreeNode 
{
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};
 
int maxDepth(TreeNode* TreeNode) 
{
   if (TreeNode==NULL) 
       return 0;
   else
   {
       int lDepth = maxDepth(TreeNode->leftChild);
       int rDepth = maxDepth(TreeNode->rightChild);
       
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
} 
 
TreeNode* newTreeNode() 
{
    struct TreeNode* TreeNode = (struct TreeNode*)
                                malloc(sizeof(struct TreeNode));
    TreeNode->leftChild = NULL;
    TreeNode->rightChild = NULL;
   
    return TreeNode;
}
   
int main()
{
    TreeNode *root = newTreeNode();
 
    root->leftChild = newTreeNode();
    root->rightChild = newTreeNode();
    root->leftChild->leftChild = newTreeNode();
    root->leftChild->rightChild = newTreeNode(); 
    root->leftChild->rightChild->leftChild = newTreeNode(); 
    
    cout <<"Hight of tree is "<< maxDepth(root) <<endl;
   
    
    return 0;
}