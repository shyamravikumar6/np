

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
uint F[101]={0};
int main(){
 int temp=0; string s="loveleetcode";
        int A[26]={0};
        for(char i:s){A[i-'a']++;}
        for(int i=0;i<26;++i){cout<<i+'a';}
        for(int i=0;i<s.size();++i){
            if(!(s[i]-'a'-temp)) temp=i; break;
        }

      
}




    
