#include<bits/stdc++.h>
using namespace std;
int tt;

void solve(){
    int N;cin>>N; int t=0;
    vector<int> A(N);
    for(int i=0;i<N;++i ){cin>>A[i]; cout<<A[i];}
    int i;int m =-1;
    for( i=0;i<N-1;++i){
            
        
           if(A[i]>A[i+1] && A[i]>m){ t++; cout<<t;}
            m=max(m,A[i]); 
   }
       if( A[i]>m) {t++;}

       cout<<t<<"\n";


}

int main(){
    cin>>tt;
    for(int i=1;i<=tt;++i){ cout<<"Case #"<<i<<": "; 
    solve();
    }
}