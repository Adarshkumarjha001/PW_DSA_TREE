#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void display(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int sum(Node* root){
    if(root==NULL) return 0;
    int ans=(root->val+sum(root->left)+sum(root->right)); 
    return ans;
}
int size(Node* root){
    if(root==NULL) return 0;
    // root ka size 1 maante haii aur solve karte haii
    int ans=1+size(root->left)+size(root->right);
    return ans;
    
}
int maxnode(Node* root){
    if(root==NULL) return INT_MIN;
    int ans=max(root->val,max(maxnode(root->left),maxnode(root->right)));
    return ans;
}
int levelofbinarytree(Node* root){
    if(root==NULL) return 0;
    int b=1+max(levelofbinarytree(root->left),levelofbinarytree(root->right));
    return b;
}



int main() {
    
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(125);
    Node* f=new Node(6);
    Node* g=new Node(79);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    display(a);
    cout<<endl;
    cout<<"Sum of binary tree is : "<<sum(a);
    cout<<endl;
    cout<<"The size of the binary tree is: "<<size(a);
    cout<<endl;
    cout<<"The max value in a binary tree is: "<<maxnode(a);
    cout<<endl;
    cout<<"The level of tree is: "<<levelofbinarytree(a);
    return 0;
}
