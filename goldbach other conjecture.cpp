#include<stdio.h>
main()
{
	int i,j,k=0,l=0,test=0,num;
	int prime[2000];
	int com_num[20000];
	int conjecte[20000];
	
	int max_num=6000;
	prime[k]=2;
	for(i=3;i<max_num;i+=2)
	{
		test=0;
		for(j=0;j<=k;j++) if(i%prime[j]==0)test++;
		if(test==0) 
		{
			k++;
			prime[k]=i;
		}
		else  
		{
			com_num[l]=i;
			l++;
		}
	}
	int n=0,max=l;
	
	for(i=0;i<=k;i++)
	{	
		for(j=1;j<=55;j++)
		{
			test=0;
			num=prime[i]+2*j*j;
			for(l=0;l<=k;l++) if(num==prime[l]) test++;//eliminete the prime numbers
			for(l=0;l<=n;l++) if(num==conjecte[l]) test++;//eliminete the repete numbers
			if(num<max_num&&test==0&&num%2!=0)
			{
				conjecte[n]=num;		
				n++;	
			}
		}
	}		
	for(i=0;i<max;i++)
	{
		test=0;
		for(j=0;j<n;j++)
		{
			if(conjecte[j]==com_num[i])test++;
		}
		if(test==0)
		{
			printf("%d\n",com_num[i]);//answer
		}
	}
}
