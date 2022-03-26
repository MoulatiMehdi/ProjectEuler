#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define limit 40000000
int *prime=(int*)calloc(limit,sizeof(int));
int max_p=1;
int phi(int num)
{
	int answer=1,i=0;
	while(num>1&&i<max_p)
	{
		int n=0;
		
		if(num%prime[i]==0)
		{
			answer*=(prime[i]-1);
			while(num%prime[i]==0)
			{
				n++;
				num/=prime[i];
			}
			answer*=pow(prime[i],n-1);
		}
		i++;
	}
	if(num!=1) answer*=(num-1);
	return answer;
}
main()
{
	int *T=(int*)calloc(limit+1,sizeof(int));
	int*length=(int*)calloc(limit+1,sizeof(int));
	int*phi_n=(int*)calloc(limit+1,sizeof(int));
	prime[0]=2;
	int i,j=1;
	for(i=3;i<=sqrt(limit);i+=2)
	{
		if(!T[i])
		{
			int k=i;
			prime[max_p]=i;
			max_p++;
			while(k*i<=limit)
			{
				T[i*k]=1;
				k+=2;
			}
		}
	}
	long long answer=0;
	
	for(i=3;i<=limit;i+=2)
	{
		if(!T[i])
		{
			int num=i;
			length[i]++;
			phi_n[i]=(i-1);
			while(num!=1&&length[i]<=25)
			{
				length[i]++;
				if(phi_n[num]==0) phi_n[num]=phi(num);
				num=phi_n[num];
			}
			if(length[i]==25)
			{
				answer+=i;
			} 
		}
	}
	printf("%lld",answer);
	

}
