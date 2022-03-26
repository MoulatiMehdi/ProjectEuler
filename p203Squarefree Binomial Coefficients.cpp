#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int_big unsigned long long

main()
{
	int_big limit_p ;
	int_big limit_b =51-1;
	int_big i,j,k=0,sum=1;
	int_big max=0;
	
	int_big *free_square=(int_big*)calloc(100000,sizeof(int_big));//free_squares
	int_big **bin=(int_big**)calloc(limit_b+1,sizeof(int_big*));//binominale
	
	bin[0]=(int_big *)calloc(limit_b+1,sizeof(int_big));
	
	for(i=0;i<=limit_b;i++)
	{
		bin[i+1]=(int_big *)calloc(limit_b+1,sizeof(int_big));
		bin[i][0]=1;
		for(j=0;bin[i][j]!=0&&j<=limit_b;j++)
		{
			bin[i+1][j+1]=bin[i][j+1]+bin[i][j];
			if(bin[i+1][j+1]>max&&i+1<=limit_b)max=bin[i+1][j+1];//biggest binomonale
		}
	}
	
	limit_p=sqrt(max);
	
	int_big *sq_p=(int_big*)calloc(limit_p+1,sizeof(int_big));//prime square
	int_big *is_p=(int_big*)calloc(limit_p+1,sizeof(int_big));//is_prime
	k=0;
	for(i=2;i<=sqrt(limit_p);i++) is_p[i]=1;
	for(i=2;i<=sqrt(limit_p);i++)
	{
		if(is_p[i])
		{
			j=i;
			
			sq_p[k]=i*i;
			k++;
			while(i*j<=limit_p)
			{
				is_p[i*j]=0;
				j++;
			}
		}
	}
	limit_p=k;
	free_square[0]=1;
	int l=1;
	int n;
	for(i=0;i<=limit_b;i++)
	{
		for(j=1;bin[i][j-1]<=bin[i][j];j++)
		{
			int test=1;
			for(k=0;sq_p[k]<=bin[i][j]&&k<limit_p;k++)
			{
				if(bin[i][j]%sq_p[k]==0)
				{
					test=0;
					break;
				}
			}
			if(test==1)
			{
				int test1=0;
				for(n=0;n<l;n++)
				{
					if(free_square[n]==bin[i][j])
					{
						test1=1;
						break;
					}
				}
				if(test1==0)
				{
					free_square[l]=bin[i][j];
					l++;
					sum+=bin[i][j];
				}
			}
			
		}
	}
	
	printf("%lld",sum);
}
