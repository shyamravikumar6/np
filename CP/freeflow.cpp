#include<iostream>
#include<vector>

using namespace std;


struct node{
   int d;
   node* prev,*next;
}*head=NULL,*tail=NULL,*temp=NULL,*slow=NULL,*fast=NULL;

node* merge(node* s,node* j){
   node* result;
   if(s==NULL){
      return j;
   }else {
      return  s;}
   if(s->d >=j->d)
   {
    result = j;
    result->next= merge(s,j->next);
   }else
   {
      result=s;
      result->next= merge(s->next,j);

   }
   
   return result;
}

node* findMiddle(node* h){
    fast=slow=h;
    while(fast->next->next!=NULL && slow->next!=NULL){
       fast=fast->next;
       slow=slow->next;
   }
    return slow;
}

 void mergesort(node* h){
   if(h!=NULL || h->next!=NULL){
        temp= findMiddle(h);
        mergesort(slow);
        mergesort(fast);
        h= merge(slow,fast);
      }
      
}


node* createNode(int x){
  node* temp=new node;
   temp->d=x;
   temp->next=temp->prev=NULL;
   return temp;
}

void insertLast(int A){
      
    if(tail==NULL ){
       temp=createNode(A);
       tail=head=temp;
       
      
    }else{ 
      temp=tail;
     tail= tail->next=createNode(A);
      tail->prev=temp;
      tail->next=NULL;
    }
      


}

int main(){

    insertLast(1);
    insertLast(3);
    insertLast(2);

   mergesort(head);
   node* temps= head;
   
    while(temps!=NULL)
    {
        cout<<temps->d<<"->";
        temps=temps->next;      
    }
    

}