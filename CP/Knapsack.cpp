#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int>t,S;
     t.push_back(1);
        if(rowIndex==0) return t;
          t.push_back(1);
         if(rowIndex==1) return t;
        
        for(int i=2;i<=rowIndex;++i){
            S.push_back(1);
            for(int j=1;j<i;++j){
                 S.push_back(t[j-1]+t[j]);
                
            }
              S.push_back(1);
              t=S;
            S.clear();
        }
        
        return t;
    }
};

int main(){
    Solution s;
    int x; cin>>x;
    vector<int> k= s.getRow(x);
    for(int i:k) cout<<i<<"\t";


}
// Best solution for solving 


       