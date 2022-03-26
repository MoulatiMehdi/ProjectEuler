#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define int_big unsigned long long 
#define limit pow(10,8)
int *T=(int*)calloc(limit+1,sizeof(int));

num_digit(int num)
{
	
	return (int)floor(log(num)/log(10)+1);
}
is_double_digit(int num)
{
	int digit[10]={0},i;
	int test=1;
	while(num!=0)
	{
		i=num%10;
		digit[i]++;
		if(digit[i]>1||digit[0]>=1) 
		{
			test=0;
			break;
		}
		num/=10;
		
	}
	return test;
}
is_prime(int_big num)
{
	if(num<=1)return 0;
	else if(num<4)return 1;
	else if(num%2==0)return 0;
	else if(num%3==0)return 0;
	else
	{
		for(int i=5;i<=sqrt(num);i+=6)
		{
			if(num%i==0||num%(i+2)==0)
			{
				return 0;
			}
		}
		return 1;
	}
}

main()
{
	int fact[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
	int *p=(int*)calloc(fact[9]+1,sizeof(int));
	int i,j,k;
	for(i=0;i<fact[9];i++)
	{

		int digit[]={1,2,3,4,5,6,7,8,9};		
		int target=i;
		for(j=8;j>=0;j--)
		{
			for(k=1;k<=9;k++)
			{
				if(fact[j]*k>target)
				{
					p[i]*=10;
					p[i]+=digit[k-1];
					target-=fact[j]*(k-1);
					int l=k-1;
					while(l<9)
					{
						digit[l]=digit[l+1];
						l++;
					}
					break;
				}
			}
		}
	}
	int answer=0;
	for(i=0;i<fact[9];i++)
	{
		if(is_prime(p[i]))
		{
			answer++;
		}
	}
	for(i=2;i<=sqrt(limit);i++)
	{
		if(!T[i])
		{
			j=i;
			if(!is_double_digit(i))T[i]=1;
			while(i*j<=limit)
			{
				T[i*j]=1;
				j++;
			}
		}
	}
	int*prime=(int*)calloc(limit,sizeof(int));
	for(i=2,j=0;i<limit;i++)
	{
		if(!T[i])
		{
			
			prime[j]=i;
			j++;
		}
	}
	answer=0;
	int max_p=j;
	int num,test,test1,test2,test3,test4;
	for(i=0;i<1000;i++)
	{
		num=prime[i];
		for(j=i+1;j<max_p;j++)
		{
			test=num*pow(10,num_digit(prime[j]));
			test+=prime[j];
			int n=num_digit(test);
			if(n>9) break;
			if(!is_double_digit(test))continue;
			
				 if(n==9)
				{
					printf("%d %d(%d)\n",prime[i],prime[j],test);
					answer++;
				}
				else
			for(k=j+1;k<max_p;k++)
			{
				test1=test;
				test1*=pow(10,num_digit(prime[k]));
				test1+=prime[k];
				
				int n=num_digit(test1);
				if(n>9) break;
				if(!is_double_digit(test1))continue;
				
				
				 if(n==9)
				{
					printf("%d %d %d(%d)\n",prime[i],prime[j],prime[k],test1);
					answer++;
				}
				else
				for(int l=k+1;l<max_p;l++)
				{
					test2=test1;
					test2*=pow(10,num_digit(prime[l]));
					test2+=prime[l];
					
					int n=num_digit(test2);
					if(n>9) break;
					if(!is_double_digit(test2))continue;
					
					
					if(n==9)
					{
						printf("%d %d %d %d(%d)\n",prime[i],prime[j],prime[k],prime[l],test2);
						answer++;
					
					}
					else
					for(int m=l+1;m<max_p;m++)
					{
						test3=test2;
						test3*=pow(10,num_digit(prime[m]));
						test3+=prime[m];
						int n=num_digit(test3);
						if(n>9) break;
						
						if(!is_double_digit(test3))continue;
						
						if(n==9)
						{
							printf("%d %d %d %d %d(%d)\n",prime[i],prime[j],prime[k],prime[l],prime[m],test3);
							answer++;
							
						}
						else
						for(int o=m+1;o<max_p;o++)
						{
							test4=test3;
							test4*=pow(10,num_digit(prime[o]));
							test4+=prime[o];
						int n=num_digit(test4);
						if(n>9) break;
						if(!is_double_digit(test4))continue;
						
						if(n==9)
						{
							printf("%d %d %d %d %d %d(%d)\n",prime[i],prime[j],prime[k],prime[l],prime[m],prime[o],test4);
							answer++;
							
						}
						}
						
					}
				}
			}
		}
	}
	
	printf("%d",answer);
}
