#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> matrix={{0,1,1,2}, 
 {0,5,0,0}, 
 {2,0,3,3}};
    int sum=0;
     for(int i=0;i<matrix.size();){
         for(int j=0;j<matrix[0].size();++j){
             if(!matrix[j][i] ){ break;}
             sum+=matrix[j][i];
             cout<<matrix[j][i];
         }
         i++;
     }

   cout<<sum;

}