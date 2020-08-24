#include<bits/stdc++.h>
using namespace std;
int tt;


string s1,s2,s3;
int**A;

void editdistance(){
   cin>>s1>>s2;
   A =new int*[s1.size()+1];
   for(int i=0;i<=s1.size();++i){
       A[i] = new int[s2.size()+1]; A[i]={0};
   }     
     for(int i=1;i<=s1.size();++i){
         for(int j=1;j<=s2.size();++j){
              if(i-1==0) A[i][j]=j-1;
               if(j-1==0) A[i][j]=i-1;
                 if(s1[i-1]==s2[j-1]) A[i][j]=A[i-1][j-1];
              else {
                      A[i][j] =1+min({A[i-1][j],A[i][j-1],A[i-1][j-1]});
                       s3.append(s2,s2[j]);   
              }
         }
     }
           cout<<s3<<"/n";
    
}

int main(){
    cin>>tt;  int j=0;
    while(tt--){
    
         cout<<"Case #"<<++j<<": ";
            editdistance();
         
        
    }
    
}