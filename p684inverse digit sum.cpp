#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int_64bit unsigned long long
int_64bit f[91];
int_64bit max=pow(2,23);
 
int* s(int_64bit num)
{
	int*tab=(int*)calloc(max,sizeof(int));
	int_64bit n=num/9;
	tab[n]+=num%9;
	for(int_64bit i=0;i<n;i++)
	{
		tab[i]+=9;
		if(tab[i]>=10)
		{
			tab[i+1]+=tab[i]/10;
			tab[i]%=10;
		}
	}
	return tab;
}
void sum(int*tab,int* answer)
{
	int_64bit i;
	for(i=0;i<max;i++)
	{
		answer[i]+=tab[i];
		if(answer[i]>=10)
		{
			answer[i+1]+=answer[i]/10;
			answer[i]%=10;
		}
	}
}
void print_in_file(int*tab)
{
	int test=0;
	for(int_64bit i=max-1;i>=0;i--)
	{
		if(tab[i]!=0) test++;
		if(test!=0)printf("%d",tab[i]);
	}printf("\n");
}

main()
{
	int**answer=(int**)calloc(88,sizeof(int*));
	int*tab;

	int_64bit i,j;
	f[0]=0;
	f[1]=1;
	for(i=2;i<=90;i++)  
	f[i]=f[i-1]+f[i-2],printf("%lld\n",f[i]);
	
	for(j=2;j<=20;j++)
	{
		answer[j]=(int*)calloc(max,sizeof(int));
		for(i=1;i<=f[j];i++)
		{
			tab=s(i);
			sum(tab,answer[j]);
		}
		printf("%lld-->",f[j]);
	}

		
}
	

