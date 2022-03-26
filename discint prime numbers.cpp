#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	int i,j,k=0,n,l,m;
	int test=0,max;
	int prime[125]={0};
	
	prime[0]=2;//first prime
	//find the others primes
	for(i=3;i<700;i+=2)
	{
		test=0;
		for(j=0;j<=k;j++)
		{
			if(i%prime[j]==0)test++;
		}
		if(test==0)
		{
			k++;
			prime[k]=i;
		}
	}
	max=k+1;//number of primes
//find the number that could divide by four prime numbers	
	
	for(m=1;m<200000;m++)
	{
		test=0;
		for(l=0;l<4;l++)//testing the four censertive integer
		{
			for(i=0;i<max;i++)
			{
				if((m+l)%prime[i]==0)
				for(j=i+1;j<max;j++)
				{
					if((m+l)%prime[j]==0)
					for(n=j+1;n<max;n++)
					{
						if((m+l)%prime[n]==0)
						for(k=n+1;k<max;k++)	if((m+l)%prime[k]==0) test++;				
					}
				}
			}
		if(test==4)
			{
				printf("--->%d\n",m);
				break;
			}	
		}
		if(test==4) break;
	}
}
