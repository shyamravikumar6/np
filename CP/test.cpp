// #include<lucky.h>

// using namespace std;
// int testcases;
// stack<char> In;
//    bool valid =true;
// int main(){
//   string A;
//   read(A);
 
//     for(char a:A){
//        if(a =='(' || a=='[' || a=='{') In.push(a); 
    

//         else {switch (a)
//         {
//         case '}': if(In.top()=='{' ){In.pop();}else{valid=false;} break;
//             /* code */
                  
        
//             case ']':  if(In.top()=='[' ){In.pop();} else {valid=false;} break;

//             case ')': if(In.top()=='(' ){ In.pop();} else {valid=false;} break;

 
//         default:
//             break;
//         }
//         }
//         if(!In.empty() and !valid) break;

//     }
    
//      if(In.empty()) write("valid"); else write("not valid");
      

// }

#include<lucky.h>
using namespace std;

int tt;
 ll A[20005]={0};
 void testcase(){
  int a; read(a);  
   for(int i=0;i<a;++i) read(A[i]); 
   int s=0,l=-1;
   for(int i=0;i<a-1;){
       int j=i;
       int k=abs(A[i+1]-A[i]);
       while( j<a-1 && (abs(A[j+1]-A[j]) == k)){j++;} 
        int max_j=j;
        l=max(l,max_j-i+1);    
i=max(i+1,j);
   }
     write(l,"\n");

 }


 int main(){
     read(tt);
    for(int t=1; t<=tt;++t){
       cout<<"Case #"<<t<<": ";testcase();
    }
 }