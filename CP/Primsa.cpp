#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
class prims{
private:
priority_queue<ii>E;vector<ii>*A;int Ed,V;vector<int>B;
public:
   prims(int Edges,int v,vector<ii>* C){
     this->Ed = Edges; this->V=v;
       B.assign(V,0);
    A = new vector<ii>[V];
    A=C;
       
       
   }
  void process(int a){
      B[a]=1;
    for(int i=0;i<A[a].size();++i){
         ii Z=A[a][i];
         if(!B[Z.second]) E.push(ii(-Z.first,-Z.second));

    }
            
  }

    int  solution(){
        int mst=0;
        process(0);
        while(!E.empty()){
            ii front = E.top();
            E.pop(); int u = -front.second; int w=-front.first;
            if(!B[u]) mst+=w;
            process(u);


        }
        return mst;
    }
};
int main(){
    
    int E,V;cin>>E>>V;
    vector<ii> R[V];int s,d,w;
    for(int i=0;i<E;++i){
        cin>>s>>d>>w;  
        R[s].push_back(ii(w,d));  
    }
    prims A(E,V,R);
    cout<<A.solution();
}