#include <stdio.h>

int main(void){
  double x, xx, x250, r, K;
  int t;
  x250=88.0;
  K=100.0;

  FILE *fp;
  fp=fopen("output,dat", "w");
  fprintf(fp, "%f, %f\n", r, x250);
  
  for(r=1.0; r<3.0; r+=0.01){
  x=x250;
  for(t=251; t<300; t++){
    xx=x+r*(1-x/K)*x;
    fprintf(fp, "%f, %f\n", r, xx);
    x=xx;
  }
}
  fclose(fp);

  return 0;
}
