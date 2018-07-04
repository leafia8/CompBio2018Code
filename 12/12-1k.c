#include <stdio.h>
#include <math.h>

int main(){

  int i,j;
  double a,A,b,c,dh,dr,m,n,P,t,T,dt,Th,xmax_th,xmax_ex,alpha,beta,gamma,s,score,x[3],xx[3];

  FILE *fp;
  fp=fopen("allergy_ode.csv","w");

  a=2.0;
  A=10.0;
  b=10.0;
  c=0.9;
  dh=0.05;
  dr=0.01;
  m=0.045;
  n=200.0;
  T=9000.0;

  Th=50.0;

  xmax_th=0;
  xmax_ex=0;

  score=0;

  alpha=0;
  beta=0;
  gamma=0;

  s=0.1;
  dt=0.1;

  for(j=0;j<2;j++){
    xmax_th=0;
    xmax_ex=0;
    x[0]=0;
    x[1]=0;

    for(i=0;i<12000;i++){
      t=dt*i;

      if(i<=T){
        if(j==0){
          P=0;
        }

        else{
          P=a;
        }
      }

      else{
        P=A;
      }

      xx[0]=x[0]+dt*(P*b*(1-c)-dr*x[0]);
      xx[1]=x[1]+dt*(P*b*c/(1+m*(x[0]+n))-dh*x[1]);

      x[0]=xx[0];
      x[1]=xx[1];

      if(i<=T){
        if(x[1]>xmax_th){
          xmax_th=x[1];
        }
      }

      else{
        if(x[1]>xmax_ex){
          xmax_ex=x[1];
        }
      }

      fprintf(fp, "%f,%f,%f,%f\n",t,x[1],xmax_th,xmax_ex);
    }

    if(j==1){
      if(xmax_th>Th){
        beta=-pow((xmax_th-Th),s);
      }
      else{
        beta=0;
      }
    }

    if(xmax_ex>Th){
      if(j==0){
        alpha=pow((xmax_ex-Th),s);
      }
      else{
        gamma=-pow((xmax_ex-Th),s);
      }
    }
    else{
      if(j==0){
        alpha=0;
      }
      else{
        gamma=0;
      }
    }
  }

  score=alpha+beta+gamma;

  printf("alpha=%f,beta=%f,gamma=%f,score=%f\n",alpha,beta,gamma,score);

  fclose(fp);
  return 0;
}
