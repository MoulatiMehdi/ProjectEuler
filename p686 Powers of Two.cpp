#include<stdio.h>
#include<math.h>
#define int_64bit unsigned long long
#include<stdlib.h>
#include<conio.h>
int_64bit max=1000000;
int num_digit(int* tab)
{
	int_64bit i=max-1;
	while(tab[i]==0) i--;
	return i;
}
void print_tab(int*tab)
{
	int test=0,i;
	for(i=max-1;i>=0;i--)
 	{
		if(tab[i]!=0)test++;
		if(test!=0)printf("%d",tab[i]);
 	}
}
int p(int L,int n)
{
	int *tab=(int*)calloc(max,sizeof(int));
	tab[0]=1;
	int i=0,j=1;
	int_64bit k;
	int num;
	while(i<n)
	{
		num=0;
		for(k=0;k<max;k++)
		{
			tab[k]*=2;
			
			if(tab[k-1]>=10&&k>0)
			{	
				tab[k]+=tab[k-1]/10;
				tab[k-1]%=10;
			}
		}
		k=num_digit(tab);
		num=tab[k]*100+tab[k-1]*10+tab[k-2];
		if(num==L)
		{
			i++;
			printf("%d--->%d\n",i,j);
		 } 
		j++;
	}
	return j-1;
}
main()
{
	printf("-->%d",p(123,678910));
}
