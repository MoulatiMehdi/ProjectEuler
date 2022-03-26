#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define int_64bit unsigned long long 
int num_digit(int_64bit a)
{
	int i;
	for(i=1;;i++) if(pow(10,i)>a) break;

	return i;
}
int num_digit_bin(int a)
{
	int p=0;
	while(pow(2,p)<=a)p++;
	return p;
}

int reverse_num(int a)
{
	int max=num_digit(a),i;
	int_64bit num,test,answer=0;
	num=a;
	
	if(max==1) answer=a;
	else
	for(i=0;i<max;i++)
	{
		test=num/pow(10,max-i-1);
		num-=test*pow(10,max-i-1);
		answer+=pow(10,i)*test;	
	}
	return answer;
}

int*reverse_tab(int*tab,int a)
{
	int*rev,i;
	int max=num_digit_bin(a);
	rev=(int*)malloc(sizeof(int)*max);
	for(i=0;i<max;i++) rev[i]=tab[max-i-1];
	
	return rev;
	
 } 
int * trans_bin(int a,int*tab)
{
	int i=0;
	int p=num_digit_bin(a);
	
	tab=(int*)malloc(sizeof(int)*p);
	int num=a;
	
	for(i=p-1;i>=0;i--)
	{
		if(pow(2,i)<=num)
		{
			if(num==0)break;
			num-=pow(2,i);
			tab[p-i-1]=1;
		}
		else tab[p-i-1]=0;
	}
	return tab;	
}

int tab_cmp(int *tab1,int *tab2,int a)
{
	int max=num_digit_bin(a);
	int i,answer=0;
	for(i=0;i<max;i++)
	{
		if(tab1[i]!=tab2[i]) 
		{
			answer++;
			break;
		}	
	}
	return answer;	
}
main()
{
	int i,rev_n,sum=0;
	int *rev_bin,*bin;	
	for(i=1;i<1000000;i=i+2)
	{
		
		bin=trans_bin(i,bin);
	 	rev_bin=reverse_tab(bin,i);
	 	
	 	rev_n=reverse_num(i);
	 	
	 	if(rev_n==i&&tab_cmp(bin,rev_bin,i)==0)
	 	{
	 		sum+=i;
		 }
	}	
	printf("\n the sum  is: %d .",sum);
  
}
