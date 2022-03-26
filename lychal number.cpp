#include<stdio.h>
#include<stdlib.h>
int num_digit(int*tab)
{
	int i;
	for(i=0;i<28;i++) if(tab[27-i]!=0||i==27) break;
	return 28-i;
	
}
int* initial_arr(int*tab,int a)
{
	int i,num,test;
	tab=(int*)malloc(sizeof(int)*28);
	num=a;
	for(i=0;i<28;i++)
	{
		test=num/10;
		tab[i]=num-test*10;
		num=test;
	}
	return tab;
}
int* reverse_num(int*tab)
{
	int i;
	int max=num_digit(tab),*arr;
	arr=(int*)malloc(sizeof(int)*28);
		
	for(i=27;i>=0;i--)
	{
		if(i>=max) arr[i]=0;
		else arr[max-i-1]=tab[i];			
	}
	return arr;
}
int is_palindrome(int *tab)
{
	int i,max=num_digit(tab),test=0;
	for(i=0;i<max/2;i++)
	{
		if(tab[i]!=tab[max-i-1])
		{
			test++;
			break;
		}
	}
	if(test==0) return test=1;
	else test=0;	
	return test;
}
main()
{
	int *num,*rev_num,lychral,inter=0,test;
	int i,j,k;
	for(i=0;i<10000;i++)
	{
		num=initial_arr(num,i);
		inter=0;
		for(j=0;j<50;j++)
		{
			rev_num=reverse_num(num);
			for(k=0;k<28;k++)
			{
				num[k]=num[k]+rev_num[k];
				if(num[k]>9)
				{
					test=num[k]/10;
					num[k+1]+=test;
					num[k]-=test*10;	
				}
			}
			inter++;
			if(is_palindrome(num))
			{
				break;
			}		
		}
		if(inter>49) lychral++;	
	}
printf("number of lycharl is :%d",lychral);
}
