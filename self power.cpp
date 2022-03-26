#include<stdio.h>
#include<math.h>
#include<conio.h>
int num_digit(int a)
{
	int i;
	for(i=1;pow(10,i)<=a;i++) continue;
	return i;
}

main()
{
	int max_num=1000,max_digit=11;
	long long sum=0;
	int tab[max_num][max_digit]={0};
	
	int i,j,num,max,test,k;
	
	for(i=0;i<max_num;i++) for(j=0;j<max_digit;j++) tab[i][j]=0;
	
	for(i=0;i<max_num;i++)
	{	
		if(i+1>=10)
		{
			num=i+1;
			max=num_digit(num);
			for(j=0;j<max;j++)
			{	
				tab[i][max-j-1]+=num/pow(10,max-j-1);
				num-=tab[i][max-j-1]*pow(10,max-j-1);	
			}	
		}	
		else tab[i][0]=i+1;
	}	
	for(i=0;i<max_num;i++)
	{
		test=0;
		for(j=0;j<i;j++)
		{
			for(k=0;k<max_digit;k++)
			{
				tab[i][k]*=i+1;
				if(k>0&&tab[i][k-1]>=10)
				{
					test=tab[i][k-1]/10;
					tab[i][k]+=test;
					tab[i][k-1]-=test*10;			
				}
			}	
		}	
	}	
	for(i=0;i<max_num;i++)
	{
		for(j=1;j<=10;j++) sum+=tab[i][max_digit-j-1]*pow(10,max_digit-j-1);			
	}	
	num=sum/pow(10,10);
	sum-=num*pow(10,10);
	printf("--->%lld",sum);	
}
