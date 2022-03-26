#include<stdio.h>
#define m 50
#define max 1000000
int main() {
  long  F[1000];
  int n;
  F[0]=1;
  for (n=1;;n++)
  {
    
    F[n]=F[n-1];
    if (n>=m) F[n]++;
    for (int j=m;j<n;j++)  F[n]+=F[n-j-1];
    
    if(F[n]>max) break;
  }
  printf("n=%d :F(m,n)=%li\n",n, F[n]);
  return 0;
}
