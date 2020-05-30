#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
// we use the int version of ’abs’

int row[4],linecounter;
int board[4][4];
void printsol(){
  
  for(int r=0;r<4;++r){
      for(int c=0;c<4;++c) {  if( row[r]==c) board[r][c]=1; printf("%d\t",board[r][c]);
  } 
  printf("\n");
  }
  row[4]={0};
}

bool place( int r,int c){
   for(int prev=0; prev<c; ++prev ){
        if(row[prev]==r or abs(row[prev]-r)== abs(prev-c )){
           return false;
        }
   }
   return true;

}

void backtrack(int c){
    if(c==4){
        linecounter++;
        printf("%d\n", linecounter);
       printsol();
       printf("\n");
    memset(board,0,sizeof(board));
    }else
    {
        
        for(int r=0;r<4;++r){

          if(place(r,c)) {row[c]=r; backtrack(c+1);}
         
      }

        /* code */
    }
    
      
}

int main(){
  linecounter=0;
  memset(board,0,sizeof(board));
    backtrack(0);
}