#include<stdio.h>

int main(void){
  int i;
  double t,dt,S,SS,I,II,R,RR;
  double b,c;

  FILE *fp;
  fp=fopen("6-4op.csv","w");

  dt=0.0001;
  b=0.002;
  c=0.1;

  t=0.0;
  S=1000.0;
  I=500.0;
  R=10.0;

  fprintf(fp,"%f,%f,%f,%f \n",t,S,I,R);

  for(i=1;i<100000;i++){
    t=dt*i;
    SS=(1-b*I*dt)*S;
    II=(1+b*S*dt-c*dt)*I;
    RR=R+c*I*dt;

    S=SS;
    I=II;
    R=RR;

    if(i%100==0){
      fprintf(fp,"%f,%f,%f,%f \n",t,S,I,R);
    }
  }
  fclose(fp);
  return 0;
}
