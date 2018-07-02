#include<stdio.h>

int main(){
  int i, j;
  int t;
  double dt=0.01;
  double u[100][100];
  double utemp[100][100];
  double v[100][100];
  double vtemp[100][100];

  double Du=1.0;
  double Dv=0.1;

  FILE *fp;

  fp=fopen("11-2.csv", "w");


  //初期化
  for(i=0; i<100; i++){
    for(j=0; j<100; j++){
      u[i][j]=1.0;
      v[i][j]=1.0;
    }
  }

  FILE *inputu;
  inputu=fopen("rd_u1.csv", "r");

  FILE *inputv;
  inputv=fopen("rd_v1.csv", "r");


//  u[49][49]=1;
//  u[49][50]=1;
//  u[50][49]=1;
//  u[50][50]=1;

//  v[49][49]=1;
//  v[49][50]=1;
//  v[50][49]=1;
//  v[50][50]=1;

  //初期値出力
  for(i=0; i<100; i++){
    for(j=0; j<100; j++){
      fscanf(inputu, "%f", &u[i][j]);
      fprintf(fp, "%f", u[i][j]);

      if(j!=99){
        fscanf(inputu, ",");
        fprintf(fp, ",");
      }
    }
    fprintf(fp, "\n");
  }

  fclose(inputu);

  for(i=0; i<100; i++){
    for(j=0; j<100; j++){
      fscanf(inputv, "%f", &v[i][j]);

      if(j!=99){
        fscanf(inputv, ",");
      }
    }
  //  fprintf(inputv, "\n");
  }

  fclose(inputv);


  for(t=1; t<5000; t++){

    //環境条件
    //i=0, j=0
    i=0;
    j=0;

    utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]
    +u[i+1][j]+u[i][99]+u[i][j-1]-4*u[i]
  [j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

   vtemp[i][j]=v[i][j]+dt*(Dv*(u[99][j]
  +u[i+1][j]+u[i][99]+u[i][j-1]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

  //i=0, j=99


  i=0;
  j=99;
utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]
+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[99][j]
+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

//i=99, j=0


i=99;
j=0;

utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]
+u[0][j]+u[i][99]+u[i][j+1]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]
+u[0][j]+u[i][99]+u[i][j+1]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

//i=99, j=99
i=99;
j=99;

utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]
+u[0][j]+u[i][j-1]+u[i][0]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]
+u[0][j]+u[i][j-1]+u[i][0]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

//i=0
i=0;
for(j=1; j<99; j++){

utemp[i][j]=u[i][j]+dt*(Du*(u[99][j]
+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[99][j]
+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

}
//i=99
i=99;
for(j=1; j<99; j++){

utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]
+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]
+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

}
//j=0
j=0;
for(i=1; i<99; i++){

utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]
+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]
+u[i+1][j]+u[i][99]+u[i][j+1]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

}
//j=99
j=99;
for(i=1; i<99; i++){

utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]
+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]
+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

}
//その他
for(i=1; i<99; i++){
  for(j=1; j<99; j++){

  utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]
  +u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i]
[j]))+dt*(u[i][j]*u[i][j]/v[i][j]-u[i][j]);

 vtemp[i][j]=v[i][j]+dt*(Dv*(u[i-1][j]
+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i]
[j]))+dt*u[i][j]*u[i][j]-dt*v[i][j];

  }
}
//更新
for(i=0; i<100; i++){
  for(j=0; j<100; j++){
    u[i][j]=utemp[i][j];
    v[i][j]=vtemp[i][j];
  }
}

//出力
if(t%500==0){
  for(i=0; i<100; i++){
    for(j=0; j<100; j++){
      fprintf(fp, "%f", u[i][j]);
      if(j!=99){
        fprintf(fp, ",");
      }
    }
  fprintf(fp, "\n");
  }
}
  }
  fclose(fp);
  return 0;
}
