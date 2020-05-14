#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        int x=coor[0][0],y=coor[0][1];
        if(coor.size()==1) return false;
        if(coor.size()==2)return true;
        int y1=coor[1][1],x1=coor[1][0],y2,x2;
        
        int  b=y1-y,a=x1-x;
		cout<<b/a;
        for(int i=2;i<coor.size();++i){
             y2=coor[i][1];x2=coor[i][0];
              if((y2-y1)*a!=b*(x2-x1)) return false;
        }
        return true;
    }
};

int main(){
	vector<vector<int>> coor={{-3,-2},{-1,-2},{2,-2},{-2,-2},{0,-2}};
	Solution* D = new Solution() ;
	if(D->checkStraightLine(coor)) cout<<"true";
	else cout<<"false";
	 
}