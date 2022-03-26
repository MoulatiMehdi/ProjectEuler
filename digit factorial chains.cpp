#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int *fact_n=(int*)malloc(sizeof(int)*10);

int num_digit(int a)
{
	int i=1;
	while(pow(10,i)<=a) i++;
	return i;
}
int digit_fact(int a)
{
	int i,answer=0,max;
	max=num_digit(a);
	int num;
	for(i=0;i<max;i++)
	{
		num=a/pow(10,max-i-1);
		a-=num*pow(10,max-i-1);
		answer+=fact_n[num];
	}
	return answer;
}

main()
{
	
	
	int i,j=0,k;
	fact_n[0]=1;
	fact_n[1]=1;
	fact_n[2]=2;
	fact_n[3]=6;
	fact_n[4]=24;
	fact_n[5]=120;
	fact_n[6]=720;
	fact_n[7]=5040;
	fact_n[8]=40320;
	fact_n[9]=362880;
	
	int test,answer=0;
	int *tab=(int*)malloc(sizeof(int)*61);
	for(i=69;i<1000000;i++)
	{
		tab[0]=i;
		
		if((i-1)%10!=0)
		{
			j=1;
			do
			{
			test=0;
			tab[j]=digit_fact(tab[j-1]);
			if(tab[j]==169)
			{
				j+=3;
				break;
				
			}
			if(tab[j]==871||tab[j]==872||tab[j]==540)
			{
				j+=2;
				break;
				
			}
			if(tab[j]==78)
			{
				j+=5;
				break;
				
			}
			
				for(k=0;k<j;k++)
				{
					if(tab[k]==tab[j])
					{
					test++;
					break;
					}
				}
			
				if(test!=0) break;
				j++;			
			}
		while(j<61);
		}
		if(j==60) answer++;
	}
	printf("the answer is : %d",answer);
}
