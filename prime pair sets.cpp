#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define int_64bit unsigned long long 
int num_digit(int_64bit a)
{
	int  i;
	for(i=1;pow(10,i)<=a;i++) continue;
	return i;
}
is_prime(int_64bit a)
{
	int_64bit i;
	int answer=1;
	if(a<2) answer=0;
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		{
			answer=0;
			break;
		}
	}
	return answer;
}
is_remarkable(int_64bit a,int_64bit b)
{
	int_64bit answer=0,num;	
	num=a*pow(10,num_digit(b));
	num+=b;
	if(is_prime(num))
	{
		num=b*pow(10,num_digit(a));
		num+=a;
		if(is_prime(num))
		{
				answer=1;
		}		
	}
	return answer;
}
main()
{
	int i,j=1,prime[3300];
	int remark1[1000];
	
	prime[0]=2;
	for(i=3;i<20000;i+=2)
	{
		if(is_prime(i))
		{
			prime[j]=i;
			j++;
		}
	}
	int max=j,k,m,l,test,min=3000000;
	int max1=0;
	printf("%d\n",max);
	for(i=1;i<6;i++)
	{
		max1=0;
		for(j=i+1;j<max;j++)
		{
			if(is_remarkable(prime[i],prime[j]))
			{
				
				remark1[max1]=prime[j];
				max1++;
			}		
		}
		test=0;
		
		for(j=0;j<max1;j++)
		{
			
			for(k=j+1;k<max1;k++)
			{
				if(is_remarkable(remark1[j],remark1[k]))
				for(l=k+1;l<max1;l++)
				{
					
					if(is_remarkable(remark1[j],remark1[l]))
					if(is_remarkable(remark1[k],remark1[l]))
					{
						for(m=l+1;m<max1;m++)
						{
							int sum=prime[i]+remark1[j]+remark1[k]+remark1[l]+remark1[m];
							
							if(is_remarkable(remark1[j],remark1[m]))
							if(is_remarkable(remark1[k],remark1[m])) 
							if(is_remarkable(remark1[l],remark1[m]))
							{
								
								if(sum<min) min=sum;
								test++;
								break;
							}
						}
					}
					if(test!=0) break;		
				}
				if(test!=0) break;
			}
			if(test!=0) break;
		}	
	}
	printf("\nthe answer is %d",min);	
}
