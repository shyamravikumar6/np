#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    bool colorGraph(vector<vector<int>>&graph,vector<int>color,int pos, int c){ 
       queue<int>Q;
       Q.push(pos);
        color[pos]=c;
         while(!Q.empty()){
             int a = Q.front();
             Q.pop();
             for(auto t =graph[a].begin(); t!=graph[a].end();++t){
                 
                 if( color[a]==color[*t]) return false;
                 else if(color[*t]!=color[a]) Q.push(*t); color[*t]=1-color[a];
             }
            
         }        
          return true;
    // color this pos as c and all its neighbours and 1-c 
 
} 
    
    
    
    
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(N+1); vector<int>color(N+1,-1);
        for(auto &P:dislikes){
            graph[P[0]].push_back(P[1]);
              graph[P[1]].push_back(P[0]);
        }
        
      return colorGraph(graph,color,1,1);    
        
    }
    
};

int main(){
    int a; a=5;
    vector<vector<int>> G = {{1,2},{1,3},{2,4}};
  Solution P;
    if(P.possibleBipartition(a,G)) cout<<"yes";
    else cout<<"NO";
}