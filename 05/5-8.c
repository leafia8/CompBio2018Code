#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  int r,M,N,x,i,j,X;
  srand(time(NULL));
  M=1;
  N=6;
  X=0;

for(j=1;j<1001;j++){
  x=0;
  for(i=0;i<100;i++){
    r=rand()%(N-M+1)+M;
    x=x+r;
    if(x>=100){
      break;
    }
  }
  X=X+i;
 if(j==1){
   printf("%d \n",X);
 }
 else if(j==5){
   printf("%d \n",X/5);
 }
 else if(j==10){
   printf("%d \n",X/10);
 }
 else if(j==100){
   printf("%d \n",X/100);
 }
 else if(j==1000){
   printf("%d \n",X/1000);
 }
}
  return 0;
}
