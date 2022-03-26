#include<stdio.h>
#define M 10000000000
void multiply_2(int *tab)
{
	int i;
	for(i=0;i<11;i++)
	{
		tab[i]*=2;
		if(tab[i-1]>=10&&i>0)
		{
			tab[i]+=tab[i-1]/10;
			tab[i-1]%=10;
		}
	}
}
void pow_2_n(int n,int *tab)
{
	int i;
	for(i=n-1;i>0;i--)
	{
		multiply_2(tab);
	}
}
main()
{
	
	int	tab[11]={0};
	unsigned long long num=0;
	tab[0]=2;
	pow_2_n(7830457,tab);
	for(int i=9;i>=0;i--)
	{
		num*=10;
		num+=tab[i];
	}
	num=num*28433+1;
	num%=M;
	printf("%lld",num);
}
