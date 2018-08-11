#include <stdio.h>

int main(void){
  int i,j;
  double t,dt;
  double x[2];
  double xx[2];
  double a,b;

  FILE *fp;
  fp=fopen("output_O-02.csv","w");

  dt=0.0001;
  a=0.30;
  b=0.40;

  t=0.0;
  //for(j=0;j<100;j++){
  x[0]=50.0;
  x[1]=10.0;
  //}
  fprintf(fp,"%f,%f,%f \n",t,x[0],x[1]);

  for(i=1;i<=1000;i++){
    t=dt*i;
    if(x[0]<x[1]){
     xx[0]=x[0]+dt*(-a*x[0]*x[1]*x[1]+a*x[0]*x[0]*x[1]+b*x[1]);
     xx[1]=x[1]+dt*(a*x[0]*x[1]*x[1]-a*x[0]*x[0]*x[1]-b*x[1]);
     x[0]=xx[0];
     x[1]=xx[1];
    }
    else{
     xx[0]=x[0]+dt*(-a*x[1]+b*x[1]*x[1]*x[1]-b*x[0]*x[1]*x[1]);
     xx[1]=x[1]+dt*(a*x[1]-b*x[1]*x[1]*x[1]+b*x[0]*x[1]*x[1]);
     x[0]=xx[0];
     x[1]=xx[1];
    }
    if(i%1==0){
      fprintf(fp,"%f,%f,%f \n",t,x[0],x[1]);
    }
  }

  fclose(fp);
  return 0;
}
