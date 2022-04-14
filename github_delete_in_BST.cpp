#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
class node
{
public:
    int info;
    node *left;
    node *right;
};
node* create(int data)
{
    node *ptr= new node;
    ptr->info=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        inorder(root->left);
        cout<<root->info<<" ";
        inorder(root->right);
    }
}
void search(node *root,int key)
{
  while(root->info!=key)
{ 
  if(key>root->info)
   {
     root=root->right;
   }
  else 
   {
     root=root->left;
   }
}
   cout<<"info= "<<root->info;
}

node* max(node *root)
{
  node *temp=root;
  while(temp->right!=NULL)
  { 
   temp=temp->right;
  }
  return temp;
} 
node* deleteinBST(node *root,int key)
{
  if(root==NULL)
   {
     return root; 
   }
  else if(key>root->info)
  {
   root->right=deleteinBST(root->right,key);
  }
  else if(key<root->info)
  {
   root->left=deleteinBST(root->left,key);
  }
  else
  {
   if(root->left==NULL)
    {
      node *temp=root->right;
      free( root);
      return temp;
    }
    else if(root->right==NULL)
    {
      node *temp=root->left;
       free(root);
      return temp;
    } 
    else 
    {
      node *temp=max(root->right);
      root->info=temp->info;
      root->right=deleteinBST(temp,temp->info);
     }  
  }
  return root;
}
int main()
{
    clrscr();
    node *root,*p1,*p2,*p3,*p4;
    root=create(40);
    p1=create(20);
    p2=create(50);
    p3=create(10);
    p4=create(30);
   
    root->left=p1;
    root->right=p2;
  
    p1->left=p3;
    p1->right=p4;
    
    inorder(root);
    cout<<endl<<endl;
    root=deleteinBST(root,20);
    cout<<endl<<endl;
    inorder(root);
  
    return 0;
}