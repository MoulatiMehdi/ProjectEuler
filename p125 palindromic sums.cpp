#include<stdio.h>
#include<math.h>
#include<stdlib.h>
is_palindromic(int num)
{
	int test=num,i=0;
	while(test!=0)
	{
		i*=10;
		i+=test%10;
		test/=10;
	}
	if(i==num)return 1;
	else return 0;
}
main()
{
	int max=pow(10,8);
	int i,j,k,l=0,answer=0;
	long long sum=0;
	int*tab=(int*)calloc(200,sizeof(int));
	
	for(i=1;i<=sqrt(max);i++)
	{
		k=i*i;		
		for(j=i+1;j<=sqrt(max);j++)
		{
			if(j*j+k>max)break;
			
			if(is_palindromic(j*j+k))
			{
				tab[l]=j*j+k;
				l++;
			} 
			
			k=j*j+k;
		
		}
	}
	for(i=0;i<l;i++)
	{
		if(tab[i]==0)continue;
		else answer++;
		for(j=i+1;j<l;j++)
		{
			if(tab[j]==tab[i]) tab[j]=0;
		}
		sum+=tab[i];
	}
	
	printf("%d(sum=%lld)",answer,sum);
}
