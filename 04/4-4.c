#include <stdio.h>

int main(void){
  int i;
  double d;

  // memo:int->double
  i=5;
  d=i;
  printf("%d,%f \n",i,d);

  // memo:double->int
  d=3.6;
  i=d;
  printf("%d,%f \n",i,d);
  
  return 0;
}
