#include<bits/stdc++.h>
using namespace std;

void first(string s,char t){
    int p=0;
    for(int i=0;i<s.size();i++)
        if(s[i]==t && s[i+1]=='-'){ p=i+3; 
            if(s[p]>=97 && s[p]<=123){ cout<<s[p]<<"\n";
            if(s[p+1]=='/'){
                if(s[p+2]>=97 && s[p+2]<=123){cout<<s[p+2]; }
                else{first(s,s[p+2]);}
            }
             break;}
            else{ first(s,s[p]);}
        } 
}  


 int main(){
      int n,i=0;
      char in;
      cout<<"no. of transtions do yo want\n";
      cin>>n;
     string s[n],l;
     while(i<n){
         cin>>s[i];
         l+=s[i];
         i++;
     }

     do{
         cout<<"enter the character of which you want\n ";
         cin>>in;
         first(l,in);
         cout<<"do you wish to continue(y/n)";
         cin>>in;
     } while(in=='y');
 }