#include<iostream>
using namespace std;
// struct node
// {
//     int data;
//     struct node*  next;
//     struct node* prev; 
// };

// struct node* head,*tail;

// void insertFirst(int d){
//     node* temp = new node;

//     if(head== NULL ){
//         head=temp;
//         temp->data=d;
//         tail=temp;
// }else{ 
//         temp->data=d;
//        temp->next=head;
//        head->prev=temp;
//        head=temp;
// }



// }

// void insertLast(int d){
//   node* temp = new node;
//     if(head==NULL){
//         tail=head=temp;
//          temp->data=d;
//     }else{
//           tail->next=temp;
//            temp->prev=tail;
//            tail=temp;
//            temp->data=d;

//     }
// }

// void mergesort(){
    
// }

// void deletenode(int pos){
//      node* temp=head;
//      for(int a=1;a<pos;a++){
//          temp=temp->next;
//      }   
//         temp->prev->next=temp->next;
//          temp->next->prev = temp->prev;
       
//            free(temp);

// }
// int main(){
//   ios::sync_with_stdio(false);
//     node* temp;
//     int i=0,val;
//     for(;i<5;i++){
//        cin>>val;
//        insertLast(val);
//     }
//       temp=head;
//       while(temp!=NULL){
//          cout<<temp->data<<"->";
//          temp=temp->next;
//      }
//        deletenode(3);
//       cout<<"NULL";
//       cout<<endl;
//      temp=tail;
//      while(temp!=NULL){
//          cout<<temp->data<<"->";
//          temp=temp->prev;
//      }
//        cout<<"NULL";
//        cout<<endl;


// }
    #include<cstdio>
    int f[3011][3011],y=998244353,r,i,j;char s[3011],t[3011];
    int main(){
        scanf("%s%s",s+1,t+1);
        for(i=1;s[i];++i)f[i][i]=(!t[i]||s[1]==t[i])*2;
        for(int l=2;s[l];++l)for(i=1;s[j=i+l-1];++i)
                f[i][j]=(f[i+1][j]*(!t[i]||s[l]==t[i])+f[i][j-1]*((!t[j]||s[l]==t[j])))%y;
        for(i=1;s[i];++i)(r+=f[1][i]*!t[i+1])%=y;
        printf("%d",r);
        return 0;
    }