#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define int_big unsigned long long

is_prime(int_big num)
{
	if(num<2)return 0;
	else if(num<4)return 1;
	else if(num%2==0)return 0;
	else if(num%3==0)return 0;
	else
	{
		int answer=1;
		for(int i=5;i<=sqrt(num);i++)
		{
			if(num%i==0||num%(i+2)==0)
			{
				answer=0;
				break;
			}
		}
		return answer;
	}
}
int* initial(int d,int n)
{
	int *tab=(int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		tab[i]=d;
	}
	return tab;
}
int_big calcule(int *tab,int n)
{
	int_big answer=0;
	
	for(int i=0;i<n;i++)
	{
		answer*=10;
		answer+=tab[i];
	}
	return answer;
}

int_big S(int d,int n)
{
	int *generate;
	int_big num=0;
	int_big sum=0;
	if(d!=0)
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(j==0&&i==0)continue;
			generate=initial(d,n);
			generate[i]=j;
			num=calcule(generate,n);
			if(is_prime(num))
			{
				
				sum+=num;
			}
		}
		
	}
	else
	{
		for(int j=1;j<10;j++)//if d==0 so the zeros must be inside two numbers 
		{
			for(int k=1;k<10;k++)
			{
				num=0;
				generate=initial(d,n);
				generate[0]=j;
				generate[n-1]=k;
				num=calcule(generate,n);
				if(is_prime(num))
				{
					sum+=num;
				}	
			}
		}
	}
	if(sum==0)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int k=0;k<100;k++)
				{		
					if(i==0&&k%10==0)continue;

					generate=initial(d,n);
					generate[i]=k%10;
					generate[j]=(k-k%10)/10;
					num=calcule(generate,n);
					if(is_prime(num))
					{
						
						sum+=num;
					}
				}
			}
		}
	}
	return sum;
}

main()
{
	int_big sum=0;
	int n=10;
	for(int i=0;i<10;i++)
	{
		sum+=S(i,n);
	}
	printf("the answer is :%lld",sum);	
}
