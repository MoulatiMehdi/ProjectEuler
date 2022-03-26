#include <stdio.h>
#include <string.h>

int mat[15][15];
int dp[32768];
int bc[32768];

int main() {
  FILE *f=fopen("matrix.txt","r");
  int i,j,k,cur;
  for(i=0;i<15;i++) for(j=0;j<15;j++) fscanf(f,"%d",&mat[i][j]);
  fclose(f);
  bc[0]=0;
  for(i=1;i<32768;i++) bc[i]=(i&1)+bc[i>>1];
  memset(dp,0,sizeof(dp));
  for(i=0;i<32768;i++) for(k=0;k<15;k++) if(!(i&(1<<k))) {
    cur=dp[i]+mat[bc[i]][k];
    if(dp[i+(1<<k)]<cur) dp[i+(1<<k)]=cur;
  }
  printf("%d\n",dp[32767]);
  return 0;
}
