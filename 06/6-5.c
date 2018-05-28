#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(void){
  double x1,x2,y1,y2,i,N;
  srand(time(NULL));
  N=1;

  FILE *fp;
  fp=fopen("output_rand.csv","w");

  for(i=0;i<10000;i++){
    x1=(((double)rand()+1)/((double)RAND_MAX+1))*N;
    x2=(((double)rand()+1)/((double)RAND_MAX+1))*N;

    y1=sqrt(-2*log(x1))*cos(2*M_PI*x2);
    y2=sqrt(-2*log(x1))*sin(2*M_PI*x2);

    fprintf(fp,"%f,%f,%f,%f\n",x1,y1,x2,y2);
  }

  fclose(fp);
  return 0;
}
