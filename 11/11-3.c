#include<stdio.h>
#include<math.h>
#define size 100

int main(){
  int i,j;
  int t;
  double dt=0.01;
  double u[size][size],v[size][size];
  double utemp[size][size],vtemp[size][size];

  double Du=0.8,Dv=0.5;

  FILE *fp;
  fp=fopen("11-3.csv","w");

  //初期化
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      u[i][j]=1.01;
      v[i][j]=0.99;
    }
  }

  //初期値入力
  FILE *inputu;
  inputu=fopen("rd_u100.csv","r");
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      fscanf(inputu,"%f",&u[i][j]);
      if(j!=size-1){
        fscanf(inputu,",");
      }
    }
  }
  fclose(inputu);

  FILE *inputv;
  inputv=fopen("rd_v100.csv","r");
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      fscanf(inputv,"%f",&v[i][j]);
      if(j!=size-1){
        fscanf(inputv,",");
      }
    }
  }
  fclose(inputv);

  //初期値出力
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      fprintf(fp,"%f",u[i][j]);
      if(j!=size-1){
        fprintf(fp," ,");
      }
    }
    fprintf(fp,"\n");
  }

  for(t=1;t<5000;t++){

  //境界条件
   //i=0,j=0
   i=0;
   j=0;
    utemp[i][j]=u[i][j]+dt*(Du*(u[size-1][j]+u[i+1][j]+u[i][size-1]+u[i][j+1]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
    vtemp[i][j]=v[i][j]+dt*(Dv*(v[size-1][j]+v[i+1][j]+v[i][size-1]+v[i][j+1]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);

    //i=0,j=99
    i=0;
    j=size-1;
     utemp[i][j]=u[i][j]+dt*(Du*(u[size-1][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
     vtemp[i][j]=v[i][j]+dt*(Dv*(v[size-1][j]+v[i+1][j]+v[i][j-1]+v[i][0]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);

    //i=99,j=0
    i=size-1;
    j=0;
     utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][size-1]+u[i][j+1]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
     vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[0][j]+v[i][size-1]+v[i][j+1]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);

    //i=99,j=99
    i=size-1;
    j=size-1;
     utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][0]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
     vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[0][j]+v[i][j-1]+v[i][0]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);

    //i=0
    i=0;
    for(j=1;j<size-1;j++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[size-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(v[size-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);
    }

    //i=99
    i=size-1;
    for(j=1;j<size-1;j++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[0][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[0][j]+v[i][j-1]+v[i][j+1]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);
    }

    //j=0
    j=0;
    for(i=1;i<size-1;i++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][size-1]+u[i][j+1]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[i+1][j]+v[i][size-1]+v[i][j+1]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);
    }

    //j=99
    j=size-1;
    for(i=1;i<size-1;i++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][0]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][0]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);
    }

  //その他
  for(i=1;i<size-1;i++){
    for(j=1;j<size-1;j++){
      utemp[i][j]=u[i][j]+dt*(Du*(u[i-1][j]+u[i+1][j]+u[i][j-1]+u[i][j+1]-4*u[i][j])+pow(u[i][j],2)/v[i][j]-u[i][j]);
      vtemp[i][j]=v[i][j]+dt*(Dv*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-4*v[i][j])+pow(u[i][j],2)-v[i][j]);
    }
  }

  //更新
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      u[i][j]=utemp[i][j];
      v[i][j]=vtemp[i][j];
    }
  }

  //出力
  if(t%500==0){
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
        fprintf(fp,"%f",u[i][j]);
        if(j!=size-1){
          fprintf(fp," ,");
        }
      }
      fprintf(fp,"\n");
    }
  }

  }
  fclose(fp);
  return 0;
}
