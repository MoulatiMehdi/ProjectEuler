#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define limit 120000
long long *rad_n=(long long*)calloc(limit,sizeof(long long));
int gcd(int a,int b)
{
	while(a!=0&&b!=0)
	{
		if(a>b)a%=b;
		else b%=a;
	}
	return a+b;
}
long long  rad(int a,int b,int c)
{
	
	return rad_n[a]*rad_n[b]*rad_n[c];
}
long long is_abc_hit(int c)
{
	
	
	
	long long answer=0;
	int i=1;
	if(c%2==0)i++;
	for(int a=1;a<c/2;a+=i)
	{
		int b=c-a;
		if(a==b)break;
		if(gcd(rad_n[a],rad_n[b])==1)
		{	
			if(rad(a,b,c)<c)
			{
				answer+=c;
			}
		}
	}
	return answer;
}
main()
{
	int T[limit+1];
	int i;
	for(i=1;i<limit;i++)
	{
		T[i]=1;
		rad_n[i]=1;
	}

	for(i=2;i<=sqrt(limit);i++)
	{
		if(T[i])
		{
			int j=i;
			while(i*j<limit)
			{
				T[i*j]=0;
				j++;
			}
		}
	}
	for(i=2;i<limit;i++)
	{
		if(T[i])
		{
			int k=1;
			while(i*k<limit)
			{
				rad_n[k*i]*=i;
				k++;
			}
		}
	}	
	
	long long answer=0;
	for(int c=1;c<limit;c++)
	{
		if(T[c]==1)continue;
		answer+=is_abc_hit(c);	
	}
	printf("the answer is ->%lld",answer);
}
//in 4 minutes
/*
#include <stdio.h>
#define N 120000ul
#define L 100
unsigned p[N] = {1,1};
unsigned long long rad[N];

int main() {
	int i=0;
	while(i<N) rad[i]=1,i++;
  unsigned long a, A[L], b, B[L], c, ans = 0;
  for (unsigned long q = 2; q < N; q++) {
    if (p[q]) continue;
    for (unsigned long r = q * q; r < N; r += q) p[r] = 1;
    for (unsigned long r = q; r < N; r += q) rad[r] *= q;
  }
  A[0] = 2, B[0] = 1;
  for (unsigned i = 0; i < L; i--) {
    a = A[i], b = B[i], c = a + b;
    if (rad[a] * rad[b] * rad[c] < c) ans += c;
    for (unsigned j = 0; j < 2; j++) {
      A[i] = a + b, B[i] = j ? a : b;
      if (A[i] + B[i] >= N) continue;
      i++;
    }
  }
  printf("%lu\n", ans);
}
*/
