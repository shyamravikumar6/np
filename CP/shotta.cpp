#include<bits/stdc++.h>
using namespace std;


void heafipy(int arr[],int n,int i){

      int lar=i;
      int l=2*i+1;
      int r= 2*i+2;
       if(l<n && arr[l]>arr[lar])   lar =l;
       if(r<n && arr[r]>arr[lar])  lar=r;

       if(lar!=i){
           swap(arr[lar],arr[i]);
           heafipy(arr,n,lar);
       }   
}
//1 2 3  4 5
/*
   1 6 2 7 8 9
     1
    
     
*/





void heapsort(int arr[],int n){
  for(int i=n/2-1;i>=0;i--){
     heafipy(arr,n,i);

  }
    //int lar=0; 
    for(int i=n-1;i>0;--i){
          // arr[0]=arr[i];
            swap(arr[0],arr[i]);
            heafipy(arr,i,0);
    }
}


int main(){
  int arr[]={1,6,2,7,8,9};
  int s = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr,s);
  for(int i:arr){
     cout<<i<<"\t";
  }


}