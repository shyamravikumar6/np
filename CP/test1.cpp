#include<bits/stdc++.h>
using namespace std; 

// unordered_map<char,int>mp;

// bool cmp(pair<char, int>& a, 
//          pair<char, int>& b) 
// { 
//     return a.first < b.first; 
// } 


// void solve(){
//     vector<pair<char, int> > Mk; 
//     int a; string s;
//    cin>>s>>a;
//      for(char t:s) mp[t]++;
//          for(auto& r:mp){Mk.push_back(r);}
//          sort(Mk.begin(),Mk.end(),cmp);
//       for(auto d=Mk.begin();d!=Mk.end();++d){
//            if(d->second!=a) {cout<<d->first;}
//       }

         
// }



// int main(){

//    solve();
   
// }


struct Node{
    int x;
    Node* next;
    Node(int a):x(a) , next(nullptr){};

};
//1->2->3;
//1->2->3->2->3     

Node* reverse(Node* h){
    Node* T;
        if(!h->next || !h) {return h;}
        T=reverse(h->next);
        h->next->next=h;
        h->next=nullptr;
    //    cout<<T->x;
        return T;
}


          




int main(){ 
   Node*h,*r ;
    h = new Node(1);
    h->next = new Node(2); h->next->next=new Node(3);
   r=reverse(h);
   while(r) {cout<<r->x; r=r->next;}

// cout<<h->next->next->x;
}



