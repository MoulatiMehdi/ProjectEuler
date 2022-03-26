#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define int_64bit unsigned long long
int num_digit(int_64bit a)
{
	int i;
	for(i=0;pow(10,i)<=a;i++)continue;
	return i;
 } 
int num_per(int_64bit a,int_64bit b)
{
	int max=num_digit(a);
	int tab_a[max],tab_b[max],i,j,help;
	for(i=0;i<max;i++)
	{
		tab_a[i]=a/pow(10,max-1-i);
		a-=tab_a[i]*pow(10,max-1-i);
		
		tab_b[i]=b/pow(10,max-1-i);
		b-=tab_b[i]*pow(10,max-1-i);
		for(j=0;j<i;j++)
		{
			if(tab_a[i]>tab_a[j])
			{
				help=tab_a[i];
				tab_a[i]=tab_a[j];
				tab_a[j]=help;
			}
			if(tab_b[i]>tab_b[j])
			{
				help=tab_b[i];
				tab_b[i]=tab_b[j];
				tab_b[j]=help;
			}
		}
			
	}
	help=1;
	for(i=0;i<max;i++)
	{
		if(tab_a[i]==tab_b[i]) continue;
		else
		{
			help=0;
			break;
		}
	}
	return help;
}

main()
{
	int_64bit i,j,max=1,sum;
	int_64bit num1,num2;
	for(i=345;i<6000;i++)
	{
		num1=i*i*i;
		max=1;
		for(j=i+1;j<10000;j++)
		{
			num2=j*j*j;
			if(num_digit(num1)!=num_digit(num2)) break;		
			if(num_per(num1,num2)) 
			{
				max++;		
				if(max==5)
				{	
					printf("\nthe answer is :%d^3=%lld",i,num1);
					exit(1);
				}	
			}
		}
	}
}
