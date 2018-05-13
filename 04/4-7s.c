#include <stdio.h>

int main(void){
  double a,b,c,d,e,f;
  double A,B,C,D;
  double BC,ApD,ADmBC,DD;


  a=2.0;
  b=3.0;
  c=5.0;
  d=4.0;
  e=3.0;
  f=1.0;

A=(-a*b*f-b*c*d)/(b*f-c*e);
B=(c*c*d+a*c*f)/(b*f-c*e);
C=(a*e*e+b*d*e)/(b*f-c*e);
D=(-b*d*f-a*e*f)/(b*f-c*e);

BC=B*C;
ApD=A+D;
ADmBC=A*D-B*C;
DD=((A-D)*(A-D))+B*C;

  printf("%f,\n%f,\n%f,\n%f\n",BC,DD,ADmBC,ApD);

  return 0;
}
