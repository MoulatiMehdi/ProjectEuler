#include<stdio.h>
#define max(a,b) (a>b)? a:b
#define num_alpha 26
long  C[num_alpha+1][num_alpha+1]={0};

long long p(int n)
{
	long long result=0;
	for(int i=1;i<n;i++)
	{
		result+=C[n][i]-1;
	}
	return result*C[num_alpha][n];
}
main()
{
	
	int i,j;
	for(i=0;i<=num_alpha;i++)
	{
		
		C[i][0]=1;
		for(j=0;j<=i;j++)
		{
			C[i+1][j+1]=C[i][j+1]+C[i][j];
		}
	}
	
	long long max_p=0;
	for(i=1;i<=num_alpha;i++)
	{
		max_p=max(max_p,p(i));
	}
	
	printf("%lld",max_p);
}
