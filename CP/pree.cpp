#include<bits/stdc++.h>
using namespace std;

void testcase(vector<string>& p){
    string pref="",suff="";
    bool ok =true; vector<string> sub;
    for(string& a:p){
         int last=-1;
        for(int i=0;i<a.size();++i){
            if(a[i]=='*'){
                if(last==-1){
                string other_pref=a.substr(0,i);
                if(other_pref.size()>pref.size()) swap(other_pref,pref);
                if(pref.substr(0,other_pref.size())!=other_pref){
                    ok=false;
                    break;
                }
                }
                else {
            sub.push_back(a.substr(last + 1, i - last - 1));
          }
          last = i;
        }
      }  //max*lol*zaffa
          //maxa*zz*zaff;
      if (!ok) {
        break;
      }
      string other_suf = a.substr(last + 1);
      if (other_suf.size() > suff.size()) {
        swap(suff, other_suf);
      }
      if (suff.substr(suff.size() - other_suf.size()) != other_suf) {
        ok = false;
        break;
      }
    }
     if (!ok) {
      cout << "*" << '\n';
    } else {
      cout << pref;
      for (auto& s : sub) {
        cout << s;
         }
      cout << suff << '\n';
    }
  }
            
        

    



int main(){
ios::sync_with_stdio(false);
cin.tie(0);
vector<string> s;
   int tt;int n;
   cin>>tt;int i=0;
    while (tt--)
    {   cin>>n; s.resize(n);
         for(int i=0;i<n;++i) cin>>s[i];
        cout<<"Case #"<<++i<<": ";
       testcase(s);cout<<endl;       
    }
    
}