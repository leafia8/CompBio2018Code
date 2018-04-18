#include <stdio.h>

int main(void){
  double x, xx, x0, r, K;
  int t;
  x0=1.0;
  r=3.0;
  K=100.0;

  FILE *fp;
  fp=fopen("output,dat", "w");

  fprintf(fp, "%d, %f\n", 0, x0);
  x=x0;
  for(t=1; t<300; t++){
    xx=x+r*(1-x/K)*x;
    fprintf(fp, "%d, %f\n", t, xx);
    x=xx;
  }
  fclose(fp);

  return 0;
}
