#include<stdio.h>
char c[] ="GATE2011";
char* p = c;

int main(){

    printf("%s",p+p[3]-p[1]);
}