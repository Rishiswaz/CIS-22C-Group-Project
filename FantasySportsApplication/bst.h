#include<iostream>
#include<conio.h>
#include<stack>
#include<queue>
#include "Team\Team.h"
#ifndef BINSTREE
#define BINSTREE
using namespace std;
typedef Team valuetype;
class Node{
  public:
         valuetype data;
         Node* left;
         Node* right;
         Node();
         Node(valuetype);
};
//OK

class BST{
  Node* findNodebyvalue(valuetype);
  Node* findparentforNode(valuetype);
  Node* findrightnode(Node*);
  void inorder(Node*);
  void postorder(Node*);
  void preorder(Node*);
  public:
  Node* root;
  Node* current;
  public:
  BST();
  void insert(valuetype);
  void remove(valuetype);
  void traverse();
  valuetype retrieve();
  void custom_print();
};

//constructor1
Node::Node(){
         left=right=NULL;
}
//constructor2
Node::Node(valuetype val){
                 data=val;
                 left=right=NULL;
}

//constructor
BST::BST(){
       root=current=NULL;
}
//insert a node with value val in tree
void BST::insert(valuetype val){
 if(root==NULL)
 root = new Node(val);
 else{
      Node* p =findNodebyvalue(val);
      if(p==0)
      {
              //cout<<"fine1";
              Node* parent=root;
              if (p != root)
              parent = findparentforNode(val);
              if(val>parent->data) parent->right=new Node(val);
              else parent->left=new Node(val);
       }
       //cout<<"fine2";
    }
}
//remove the node if value is val
void BST::remove(valuetype val){
 Node* p = findNodebyvalue(val);
 if(p!=0){
          //if both of child of node are null(leaf node)
          if(p->left==NULL&&p->right==NULL){
                if(p!=root){
                    Node* parent= findparentforNode(val);
                    if(val<parent->data) parent->left=NULL;
                    else parent->right=NULL;
                    }
                                     else root=NULL;
                     delete (p);
          }
          //if only left child is not null
          else if(p->left!=NULL&&p->right==NULL){
               if(p!=root){
                Node* parent=findparentforNode(val);
                if(val<parent->data) parent->left=p->left;
                else parent->right=p->left;
                }
                                else root=NULL;
                            delete (p);
          }
          //if only right child is not null
          else if(p->left==NULL&&p->right!=NULL){
               if(p!=root){
                Node* parent=findparentforNode(val);
                if(val<parent->data) parent->left=p->right;
                else parent->right=p->right;
                }
               else root=NULL;
               delete (p);
          }
          //if both child are not null
                      else{
               Node* righty=findrightnode(p->left);
               Node* parent=findparentforNode(righty->data);
               p->data=righty->data;
               if(parent!=p) parent->right=righty->left;
               else p->left=righty->left;
           }
    }
}
//fins node with a value key
Node* BST::findNodebyvalue(valuetype key){
  Node* p =root;
  while((p!=NULL)&&(p->data!=key)){
                                   if(key<p->data)p=p->left;
                                   else p=p->right;
                                   }
   return p;
}
//find parent of a node with value key
Node* BST::findparentforNode(valuetype key){
  Node* p =root;
  Node* q=0;
  while((p!=NULL)&&(p->data!=key)){
                                   q=p;
                                   if(key<p->data)p=p->left;
                                   else p=p->right;
                                   }
   return q;
}
//finds the most right of a node p(means immediate succesor of p in inorder representation)
Node* BST::findrightnode(Node* p){
  Node* righty=p;
  while(righty->right!=NULL)
  righty=righty->right;
  return righty;
}
//inorder
void BST::inorder(Node* p){
 if(p!=NULL){
             inorder(p->left);
             cout<<p->data<<" ";
             inorder(p->right);
 }
}
//postorder
void BST::preorder(Node* p){
 if(p!=NULL){
             cout<<p->data<<" ";
             preorder(p->left);
             preorder(p->right);
 }
}
//postorder
void BST::postorder(Node* p){
 if(p!=NULL){
             postorder(p->left);
             postorder(p->right);
             cout<<p->data<<" ";
 }
}

void BST::traverse(){
 cout<<"Preorder: ";
 preorder(root);
 cout<<endl<<"Inorder: ";
 inorder(root);
 cout<<endl<<"PostOrder: ";
 postorder(root);
 cout<<endl;
}

//to print tree hightwise i.e. all nodes at h1, then all nodes at h2, then at h3
void BST::custom_print(){
 //Node* temp;
 if(root==NULL)
 return;
 queue<Node*> Q;
 Q.push(root);
 //Q.push(NULL);
 while(!Q.empty()){
                   current=Q.front();
                   cout<<current<<" ";
                   Q.pop();
                   Q.push(current->left);
                   Q.push(current->right);
                   }
}

#endif

