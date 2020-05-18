#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;


class Prim{
private:
 int *id; vector<pair<int,ii>>E;int mst=0;
 public:
    Prim(int N){
     this->id=  new int(N);
     memset(id,-1,sizeof(int)*N);
    }
      bool issame(int a,int b){
            return a==b;
      }
       int find(int *id, int i){
            if(id[i]==-1) return i;
            return find(id,id[i]);
       }
      void unionset(int a,int b){
           int xset = find(id, a);  
    int yset = find(id, b);  
    if(xset != yset) 
    {  
        id[xset] = yset;  
    }  
      }
    int  Prims(vector<pair<int,ii>>&A){
     this->E=A;
        sort(E.begin(),E.end());
        // cout<<E[5].first;
        for(int i=0;i<E.size();++i){
            int x = find(id,E[i].second.first);  
        int y = find(id, E[i].second.second);  
            if(!issame(x,y)){this->mst+=E[i].first;}
            unionset(E[i].second.first,E[i].second.second);
        }
        return this->mst;
    }
    
};

   int main(){
       vector<pair<int,ii >>W;
        int node,e; cin>>node>>e;
        Prim Q(node); int w,x,y;
        for(int i=0;i<e;++i){
            cin>>w>>x>>y; W.push_back({w,{x,y}});
        }
        cout<<Q.Prims(W);


   }