#include <stdio.h>

#define size 100

int rule(int x, int y,int cell[][size]);

int main(void){
  int t,i,j;
  int cell[size][size];
  int temp[size][size];

  FILE *fp;
  fp=fopen("CGL.csv","w");

  FILE *input;
  input=fopen("CGLinput.csv","r");

  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      cell[i][j]=0;
      temp[i][j]=0;
    }
  }

  //初期値？
  /*
  cell[50][50]=1;
  cell[51][52]=1;
  cell[50][52]=1;
  cell[49][52]=1;
  cell[49][51]=1;
  */
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      fscanf(input,"%d",&cell[i][j]);
      //printf("%d",cell[i][j]);
      if(j!=size-1){
	fscanf(input,",");
      }
    }
  }
  fclose(input);

  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      fprintf(fp,"%d",cell[i][j]);
      if(j!=size-1){
        fprintf(fp,", ");
      }
    }
    fprintf(fp,"\n");
  }

  //繝｡繧､繝ｳ繝ｫ繝ｼ繝�
  for(t=1;t<200;t++){
    //譖ｴ譁ｰ
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
	temp[i][j]=rule(i,j,cell);
      }
    }
    //蜃ｺ蜉�
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
	cell[i][j]=temp[i][j];
	fprintf(fp,"%d",cell[i][j]);
	if(j!=size-1){
	  fprintf(fp,", ");
	}
      }
    fprintf(fp,"\n");
    }
  }
  fclose(fp);
  return 0;
}

int rule(int x, int y, int cell[][size]){
  int count=0;
  int i,j;
  if((x!=0)&&(x!=size-1)&&(y!=0)&&(y!=size-1)){
    for(i=x-1;i<=x+1;i++){
      for(j=y-1;j<=y+1;j++){
	count+=cell[i][j];
      }
    }
    count-=cell[x][y];
  }
  else{
    //x=0
    if(x==0&&y!=0&&y!=size-1){
      for(i=x;i<=x+1;i++){
	for(j=y-1;j<=y+1;j++){
	  count-=cell[i][j];
	}
      }
      for(j=y-1;j<=y+1;j++){
	count+=cell[size-1][j];
      }
      count-=cell[x][y];
    }
    //x=size-1
    else if(x==size-1&&y!=0&&y!=size-1){
      for(i=x-1;i<=x;i++){
	for(j=y-1;j<=y+1;j++){
          count+=cell[i][j];
        }
      }
      for(j=y-1;j<=y+1;j++){
        count+=cell[0][j];
      }
      count-=cell[x][y];
    }
    //y=0
    else if(x!=0&&x!=size-1&&y==0){
      for(i=x-1;i<=x+1;i++){
	for(j=y;j<=y+1;j++){
	  count+=cell[i][j];
	}
	count+=cell[i][0];
      }
      count=-cell[x][y];
    }
    //y=size-1
    else if(x!=0&&x!=size-1&&y==size-1){
      for(i=x-1;i<=x+1;i++){
	for(j=y;j<=y+1;j++){
	  count+=cell[i][j];
	}
	count+=cell[i][size-1];
      }
      count-=cell[x][y];
    }

    //x=0 y=0
    else if(x==0&&y==0){
      count+=cell[0][1];
      count+=cell[1][0];
      count+=cell[1][1];
      count+=cell[size-1][0];
      count+=cell[0][size-1];
      count+=cell[size-1][1];
      count+=cell[1][size-1];
      count+=cell[size-1][size-1];
    }
    //x=0 y=size-1
    else if(x==0&&y==size-1){
      count+=cell[1][0];
      count+=cell[1][size-1];
      count+=cell[1][size-2];
      count+=cell[0][size-2];
      count+=cell[size-1][size-2];
      count+=cell[size-1][size-1];
      count+=cell[size-1][0];
      count+=cell[0][0];
    }
    //x=size-1 y=0
    else if(x==size-1&&y==0){
      count+=cell[0][1];
      count+=cell[size-1][1];
      count+=cell[size-2][1];
      count+=cell[size-2][0];
      count+=cell[size-2][size-1];
      count+=cell[size-1][size-1];
      count+=cell[0][size-1];
      count+=cell[0][0];
    }
    //x=size-1 y=size-1
    else if(x==size-1&&y==size-1){
      count+=cell[0][0];
      count+=cell[0][size-1];
      count+=cell[0][size-2];
      count+=cell[size-1][size-2];
      count+=cell[size-2][size-2];
      count+=cell[size-2][size-1];
      count+=cell[size-2][0];
      count+=cell[size-1][0];
    }
  }
  //printf("%d",count);
  if(count==3){
    return 1;
  }
  else if(count==2){
    return cell[x][y];
  }
  else {
    return 0;
  }
}
