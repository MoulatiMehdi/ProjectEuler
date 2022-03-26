#include<stdio.h>
#include<math.h>
#include<conio.h>
int perm(int* tab)
{
	int num;
		num=tab[0];
		tab[0]=tab[1];
		tab[1]=tab[2];
		tab[2]=num;	
		
	num=tab[0]*1000+tab[1]*100+tab[2]*10+tab[3];
	return num;	
}
int circle_prime(int a)
{
	int tab[4],i,num;
	num=a;
	for(i=0;i<4;i++)
	{
		tab[i]=num/pow(10,3-i);
		num-=tab[i]*pow(10,3-i);		
	}
	num=perm(tab);	
	return num;	
}
main()
{
	int i,j,k=0,max_num=10000,test=0;
	int prime[1254];
	for(i=1000;i<max_num;i++)
	{
		test=0;
		for(j=2;j<sqrt(i);j++)
		{
			if(i%j==0)
			{
				test++;
				break;
			}	
		}
		if(test==0) 
		{
			prime[k]=i;
			k++;	
		}
	}
	int max=k,num,diff[2]={0};
	for(i=0;i<max;i++)
	{
		test=0;
		num=prime[i];
		for(j=0;j<2;j++)
		{	
			diff[j]=num;
			num=circle_prime(num);
			diff[j]-=num;
			if(diff[j]<0)diff[j]*=-1;	
			for(k=0;prime[k]<=num;k++)
			if(prime[k]==num)
			{
				test++;
				break;
			}
		}
		if(test==2) 
		{
			if(diff[0]==diff[1]&&diff[0]!=0&&prime[i]!=1487)	
			printf("%d,%d,%d\n",circle_prime(circle_prime(prime[i])),circle_prime(prime[i]),prime[i]);
		}
	}
}
