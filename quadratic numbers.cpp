#include<stdio.h>
#include<math.h>
main()
{
	int max_prime=170;
	int prime[max_prime]; 
	
	int i,j,k=1,m,max,test;
	
	prime[0]=2;
	for(i=3;i<=1000;i++)
	{
		test=0;
		for(j=0;j<k;j++)
		{
			if(i%prime[j]==0)test++;	 
			
		}
		if(test==0)
		{
			prime[k]=i;	
			k++;	
		}
	}
	max_prime=0;
	int max_j=0,max_i=0;
	long long num;
	for(i=-1000;i<=1000;i++)// i for b
	{
		for(j=-999;j<1000;j++)// j for a
		{
			max=0;
			for(m=0;m<=1000;m++)
				{
					test=0;
					num=m*m+m*j+i;
					if(num<=0)break;		
					for(k=0;k<sqrt(num);k++)
						{
							if(num%prime[k]<=0)
							{
								test++;
								break;
							}
						}
					if(test==0)  max++;	
					else break;			
				}
			
			if (max>max_prime)
				{
				max_prime= max;
				max_i=i;
				max_j=j;
				} 		
		}
	}
	printf("\n--->n_max=%d a=%d b=%d\n",max_prime,max_j,max_i);//
    printf("%d*%d=%d",max_j,max_i,max_i*max_j);
}	


