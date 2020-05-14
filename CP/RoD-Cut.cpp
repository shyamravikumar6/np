#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int main(){
uint a,b;
    cin>>a>>b;//unordered_map<int,int>R;
    vector<int>N(a),P(b),D(a); int minT=INT_MAX,T=0;
    for(int i=0;i<a;++i) cin>>N[i];
      for(int i=0;i<b;++i) cin>>P[i];
   for(int i=0;i<a;++i) D[i]=N[i];
     //cout<<D[0];
     for(int i=1;i<a;i++)D[i]+=D[i-1];

     for(int i=0;i<b;++i){
         for(int j=0;j<a;++j){
             //cout<<D[j];
             if((P[i]-D[j])<=0){

                 T=j+1;
                goto h; break;    
             }
         }
        h: minT=min(minT,T);
         T=0;
     }
     cout<<minT;
}