#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h> 
#define int_big unsigned long long
#define limit 100000
int_big *prime=(int_big*)calloc(pow(10,8),sizeof(int_big));
int_big max_p=limit;
int_big pgcd(int_big a,int_big b)
{
	while(a!=0&&b!=0)
	{
		if(a>b) a%=b;
		else b%=a;
	}
	return a+b;
}
double phi(int_big num)
{
	int_big answer=1;
	int_big a=num;
	int_big i=0;
	while(a!=1&&i<max_p)
	{
	
		if(a%prime[i]==0)
		{
			answer*=prime[i]-1;
			int n=0;
			a/=prime[i];
			while(a%prime[i]==0)
			{
				a/=prime[i];
				n++;
			}
			
			answer*=pow(prime[i],n);
		}
		i++;
	}
	if(a!=1) answer*=a-1;

	
	
	return answer/double(num-1);
	
}

main()
{
	double target=15499/(double)94744;
	
	int_big i,j,k=0;
	int_big*t=(int_big*)calloc(max_p,sizeof(int_big));
	
	for(i=2;i<limit;i++) t[i]=1;
	
	for(i=2;i<=sqrt(limit);i++)
	{
		if(t[i])
		{
			j=i;

			prime[k]=i;
			k++;
			while(i*j<limit)
			{
				t[i*j]=0;
				j++;
			}
		}
	}
	for(i=sqrt(limit);i<limit;i++)
	{
		if(t[i])
		{
			prime[k]=i;
			k++;
		}
	}
	double a;
	max_p=k;
	int_big num=1;
	int_big min;
	for(i=0;i<max_p;i++)
	{
		num*=prime[i];
		a=phi(num);
		if(a<target)
		{
			min=num;
			break;
		} 
	}
	num=1;
	int_big num1;
	for(i=0;i<max_p;i++)
	{
		num*=prime[i];
		a=phi(num);
		if(a-target<0.01)
		{
			for(j=2;;j++)
			{
				num1=num*j;
				a=phi(num1);
				
				
				if(num1>min)break;
				if(a<target)
				{
					if(num1<min)min=num1;
					printf("%lld---->%.16f\n",num1,a);
					break;
				}
			}
		}
		if(a<target) break;
	}
}
