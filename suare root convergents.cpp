#include<stdio.h>
#include<math.h>
#include<conio.h>
int num_digit(int* tab)
{
	int i;
	for(i=499;tab[i]==0;i--) continue;
	return i+1;
}
void num_cpy(int *to,int*from)
{
	int i;
	for(i=0;i<500;i++)
	{
		to[i]=from[i];
	}
}
void int_sum(int*sum,int*num,int*denum)
{
	int i,reste=0;
	for(i=0;i<500;i++)
	{
		sum[i]=num[i]+denum[i]+reste;
		reste=0;
		if(sum[i]>=10)
		{
			reste=sum[i]/10;
			sum[i]-=reste*10;
		}			
	}	
}
main()
{
	int last_denum[500]={0},denum[500]={0};
	int num[500]={0},high=0,i;
	last_denum[0]=1;
	denum[0]=2;
	for(i=0;i<1000;i++)
	{
		int_sum(num,last_denum,denum);

		if(num_digit(num)>num_digit(denum))
		{
			high++;
		}
		
		num_cpy(last_denum,denum);
		int_sum(denum,last_denum,num);		
	}
	printf("%d",high);	
}
