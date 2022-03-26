#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int num_digit(int num)
//numbers of  digits 
{	if (num==0)num=1;
	num=log(num)/(double)log(10)+1;
	return num;	
}
int *divide_digit(int a)
//divide number to digits
{
	int i=0,num;
	int max_digit=num_digit(a);
	int *tab=(int *)calloc(max_digit,sizeof(int));
	num=a;
	while(num!=0)
	{
		tab[i]=num%10;
		num/=10;
		i++;
	}
	return tab;
}
void circle_digit(int max_digit,int *tab)
//reverse digits place
{
	int i;
	int num=tab[0];
	
	for(i=0;i<max_digit-1;i++) tab[i]=tab[i+1];	
	tab[i]=num;
}
is_prime(int num)
{
	int i,answer=1;
	if(num<=1)answer=0;
	else if(num<4)answer=1;
	else if(num%2==0)answer=0;
	else if(num%3==0)answer=0;
	else
	{
		for(i=5;i<=sqrt(num);i+=6)
		{
			if(num%i==0||num%(i+2)==0)
			{
				answer=0;
				break;
			}
		}
	}
	return answer;
}
main()
{
	int max=1000000;
	
	int i,j,k=0,n;	
	int max_digit,sum=0;
	int prime[100000]={0};
	
	prime[0]=2;
	for(i=3;i<max;i+=2)
	//finnd the primes numbers
	{
		if(is_prime(i))
		{
			k++;
			prime[k]=i;			
		}	
	}	
	max_digit=k;
	int *tab,mul=0;
	for(i=0;i<=max_digit;i++)
	//test all the primes if they are circular primes
	{
		n=0;
		if(prime[i]<=11)
		{
			sum++;
		} 
		else
		{
			n=0;
			max=num_digit(prime[i]);
			//divide the number to digits 	
			tab=divide_digit(prime[i]);
			
			for(j=1;j<max;j++)
			{
				
				circle_digit(max,tab);
				mul=0;
				for(k=0;k<max;k++)
				{
					mul*=10;
					mul+=tab[max-k-1];
				}	
				if(is_prime(mul)) n++;
				else break;
			}
			if(n==max-1) 	sum++;
		}		
	}
	printf("the number of circular prime is %d\n",sum);		
}

