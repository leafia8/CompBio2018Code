#include<stdio.h>

int main(void){
  int i, Ej[10];
  double t, dt, b, c, SS, S, II, I, RR, R, E, Ei, EE, j;
  double e;//外出しているときの感染率

  FILE *fp;
  fp=fopen("output_03.txt","w");

  dt=1;
  S=30.0;
  E=5.0;
  I=0.0;
  R=0.0;
  b=0.025;
  c=0.0034;
  e=0.0044;
  Ej[0]=E;

  t=0.0;
  fprintf(fp, "%d, %d\n", Ej[0], 0);
  fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);

i=1;
    t=dt*i;
    SS=S-(b+e)*S*E*dt;
    EE=E+(b+e)*S*E*dt;
    II=-c*I*dt;
    RR=R+c*I*dt;

    Ej[i]=(b+e)*S*E*dt;
    j=(b+e)*S*E*dt;

    S=SS;
    E=EE;
    I=II;
    R=RR;


      fprintf(fp, "%d, %d, %f\n", Ej[i], i, j);
      fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);

for(i=2; i<=4; i++){
  t=dt*i;
  Ei=Ej[i-2];

  SS=S-(b+e)*S*E*dt;
  EE=E+(b+e)*S*E*dt-Ei*dt;
  II=I+Ei*dt-c*I*dt;
  RR=R+c*I*dt;

  Ej[i]=(b+e)*S*E*dt;
  j=(b+e)*S*E*dt;

  S=SS;
  E=EE;
  I=II;
  R=RR;

  fprintf(fp,"%d, %d, %f\n", Ej[i], i, j);

    fprintf(fp,"%f, %f, %f, %f, %f\n", t, S, E, I, R);
 }

 for(i=5; i<=6; i++){
   t=dt*i;
   Ei=Ej[i-2];

   SS=S-b*S*e*dt;
   EE=E+b*S*e*dt-Ei*dt;
   II=I+Ei*dt*-c*I*dt;
   RR=R+c*I*dt;

   Ej[i]=b*S*e*dt;
   j=b*S*e*dt;

   S=SS;
   E=EE;
   I=II;
   R=RR;
   j=j+1;

   fprintf(fp, "%d, %d, %f\n", Ej[i], i, j);
   fprintf(fp, "%f, %f, %f, %f, %f\n", t, S, E, I,  R);
 }
  fclose(fp);
  return 0;
}
