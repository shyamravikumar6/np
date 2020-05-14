#include<iostream>
using namespace std;
struct node{
int data;
node* left;
node* right;

}*root=NULL;

node* newnode( int val){
    if(root==nullptr){
        root = (struct node*)malloc(sizeof(struct node));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
    }
    return root;
}

node* insert(node* start, int val){
    if(start==NULL){
      return newnode(val);
    }else if(val<=start->data){
        start->left= insert(start->left,val);
        return start;
    }else{
        start->right= insert(start->right,val);
        return start;
    }
    
    
}

int main(){
       node* temp;
      root=insert(root,3);
      insert(root,2);
      insert(root,7);
      insert(root,1);
      temp=root;

    
}