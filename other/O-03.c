#include <stdio.h>

int main(void){
  int i,j;
  double t,dt;
  double x[2];
  double xx[2];
  double a,b,c;

  FILE *fp;
  fp=fopen("output_O-03.csv","w");

  dt=0.0001;
  a=0.20;
  b=0.15;
  c=0.30;

  t=0.0;

  x[0]=55.0;
  x[1]=5.0;

  fprintf(fp,"%f,%f,%f \n",t,x[0],x[1]);

  for(i=1;i<=100000;i++){
    t=dt*i;
    xx[0]=x[0]+dt*(-a*x[0]+b*x[1]+c*(x[1]/x[0]-1)*x[0]*x[1]);
    xx[1]=x[1]+dt*(a*x[0]-b*x[1]-c*(x[1]/x[0]-1)*x[0]*x[1]);
    x[0]=xx[0];
    x[1]=xx[1];

    if(i%100==0){
      fprintf(fp,"%f,%f,%f \n",t,x[0],x[1]);
    }
  }

  fclose(fp);
  return 0;
}
