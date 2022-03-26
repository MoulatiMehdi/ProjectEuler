#include<stdio.h>
#include<stdlib.h>
#define limit 15
#define int_big unsigned long long
int_big fact(int num)
{
	if(num<=0) num=1;
	int_big i=1;
	while(num!=1)
	{
		i*=num;
		num--;
	}
	return i;
}
main()
{
	int_big **c=(int_big**)calloc(limit+1,sizeof(int_big*));
	int i,j;
	
	
	for(i=0;i<=limit+1;i++)
	c[i]=(int_big*)calloc(limit+1,sizeof(int_big));
	
	
	c[0][0]=1;
	for(i=0;i<=limit;i++)
	{
		for(j=0;j<=i;j++)
		{
			
			c[i+1][j+1]=c[i][j]*i+c[i][j+1];
		}
		c[i+1][0]=1;
		
	}
	int_big sum=0;
	int_big fact_limit=fact(limit+1);
	for(j=1;j<=(limit+1)/2;j++)
	{
		sum+=c[limit+1][j-1];
	}
	printf("the probabilitie to win is P(win)=%lld/%lld\n",sum,fact_limit);
	printf("the banker need to save : %.0f",fact_limit/(float)sum);
}
