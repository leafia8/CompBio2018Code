#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 200

int main(void){
  int a[N],aa[N],i,t,r1,r2,r,k,A,S,Y,T;

  srand(time(NULL));

FILE *fp;
fp=fopen("5-10fp.dat","w");

for(k=(N/10);k<N+1;k+=(N/10)){
  T=0;
  Y=0;
for(S=0; S<1000; S++){
  for(i=0;i<k;i++){
    a[i]=0;
  }
  for(i=k;i<N;i++){
    a[i]=1;
  }

  for(i=0;i<N;i++){
  }

    for(t=0;t<500;t++){
      A=0;
      for(i=0;i<N;i++){
        r1=rand()%N;
        r2=rand()%N;
        r=rand()%2;
        if(r==0){
          aa[i]=a[r1];
        }
        if(r==1){
          aa[i]=a[r2];
        }
      }
        for(i=0;i<N;i++){
          a[i]=aa[i];
        }

    for(i=0;i<N;i++){
      A=A+a[i];
    }
      if(A==0){
        Y=Y+1;  //成功した回数の合計
        T=T+t; //変異体になった時の合計の世代数　
        break;
      }
  }
//  printf("%d\n", t+2);

  if(Y==100){
    break;
  }
}
fprintf(fp,"%d\n",T/100);
}
fclose(fp);
    return 0;
}
