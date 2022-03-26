#include<stdio.h>
#include<stdlib.h>
#include<math.h>
const int N=5;
int max=pow(2,N);

test(int*tab,int k)
{
	int num=0;
	int i=0,j=0,max1=0;
	int answer=1;
	
	int dif[k+1],test;
	
	
	for(i=N-1;i<k;i++)
	{
		test=0;
		num%=(int)pow(10,N-1);
		num*=10;
		num+=tab[i%k];		
		for(j=0;j<max1;j++)
		{
			if(dif[j]==num)
			{
				test=1;
				break;
			}
		}
		if(test==0) dif[j]=num,max1++;
		else
		{
			answer=0;
			break;
		}		
	}
	return answer;
}
int *tab=(int*)calloc(max,sizeof(int));
int *tab1=(int*)calloc(max,sizeof(int));

long long  S(int N,int j)
{
	long long answer=0;
	if(j==max) 
	{
		if(test(tab,j+N)&&test(tab1,j+N))
		{
			for(int i=N;i<max;i++)
			{
				answer+=tab[i]*pow(2,max-i-1);
			}
			return answer;
		}
		else return 0;
	}
	
	tab[j]=0;
	tab1[max-j-1+N]=0;
	if(test(tab,j))	answer+=S(N,j+1);
	
	tab[j]=1;
	tab1[max-j-1+N]=1;
	if(test(tab,j)) answer+=S(N,j+1);
	
	return answer;
}
main()
{

	printf("-->%lld",S(N,N));
}
