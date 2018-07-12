#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(void){
  FILE *fp;
  fp=fopen("13-3op.csv","w");

  int i;
  double t,tt;
  double S,SS,I,II,R,RR;
  double b,c;
  double e[3];
  double ran,ran2;

  b=0.000001;
  c=0.001;
  S=10000;
  I=1;
  R=0;
  t=0;
  fprintf(fp,"%f,%f,%f,%f\n",t,S,I,R);
  srand((unsigned)time(NULL));

//各イベントの確率を設定
for(i=1;i<=20000;i++){
  e[1]=b*S*I;
  e[2]=c*I;
  e[0]=e[1]+e[2];

  //次のイベントまでのタイムステップを設定
  ran=(double)rand()/RAND_MAX;
  while(ran==0||ran==1){
    ran=(double)rand()/RAND_MAX;
  }
  tt=t+log(1/ran)/e[0];
  t=tt;

  //確立に応じてイベントを設定
  ran2=(double)rand()/RAND_MAX;

  if(0<=ran2 && ran2<=e[1]/e[0]){
    SS=S-1;
    II=I+1;
    S=SS;
    I=II;
  }
  else{
    II=I-1;
    RR=R+1;
    I=II;
    R=RR;
  }

  fprintf(fp,"%f,%f,%f,%f\n",t,S,I,R);
}
fclose(fp);
return 0;
}
