#include<iostream>
#include<vector>
#include<string>
using namespace std;

string s;
vector<char> ch,op;


int precedence(char* s){
  if(*s=='^') return 4;
  else if(*s=='/'|| *s=='*') return 3;
  else if(*s=='+'||*s=='-') return 2;
  else if(*s=='('||*s==')') return 1;
  else return -1;
}

void infixtopostfix(){
  for(int i=0;i<s.length();i++)
     if((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z'))
      { 
	    ch.push_back(s[i]);
	   }else if(op.empty()){
		   if(s[i]=='(')
		    op.push_back(s[i]);
		   else op.push_back(s[i]); 
		   
	   }else{
		if(!op.empty())
		    if(precedence(&s[i])>precedence(&op.back())){ op.push_back(s[i]);}
			else if(precedence(&s[i])<=precedence(&op.back())){ch.push_back(s[i]);}
			
	   }
   


}

int main(){
getline(cin,s);
infixtopostfix();
for(auto i=op.begin();i!=op.end();i++)
   cout<<*i;

for(auto i=ch.begin();i!=ch.end();i++)
   cout<<*i;
}