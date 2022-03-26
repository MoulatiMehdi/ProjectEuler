#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
proper_divisor(int num)//sum of all divisor of num
{
	int answer=1,i=2;
	while(i<=sqrt(num))
	{
		if(num%i==0)
		{
			answer+=i;
			answer+=num/i;
		}
		i++;
	}
	return answer;
}
is_prime(int num)
{
	int i;
	int answer=1;
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
	int max=1000000,i,j=0,k;
	int* tab=(int*)calloc(max,sizeof(int));
	tab[0]=0;
	int max_chain=0;
	int min_member=NULL;
	int min;
	
	
	for(i=1;i<max;i++)
	{
		if(is_prime(i)) tab[i]=2;
		else tab[i]=proper_divisor(i);
	}
	int*chain=(int*)calloc(max,sizeof(int));
	for(i=0;i<max;i++)
	{
		j=1;
		chain[0]=i;
		int test=1;
		min=i;
		while(1)
		{
			chain[j]=tab[chain[j-1]];
			if(chain[j]==chain[0])break;
			if(chain[j]>max)
			{
				test=0;
				tab[i]=1;
				break;
			}
			
			if(min>chain[j])min=chain[j];
		
			for(k=0;k<j;k++)
			{
				if(chain[k]==chain[j])
				{
					test=0;
					break;
				}
			}
			if(test==0)break;
			j++;	
		}
		if(test==1)
		{		
			if(max_chain==j)
			{
				
				if(min_member>min)
				{
						min_member=min;
				}
			}
			else if(max_chain<j)
			{
				max_chain=j;
				min_member=min;
					
			}			
		}
	}
	printf("max_chain= %d,smaller member=%d",max_chain,min_member);
}
