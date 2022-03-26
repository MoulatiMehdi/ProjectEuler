#include<stdio.h>
#include<math.h>
unsigned long long fact(int a,int min)//answer=n*(n-1)*...*(min+1)
{
	unsigned long long answer=1;
	int i;
	
	for(i=a;i>min;i--) answer*=i;	
	return answer;	
}
int C(int k,int n)
{
	int answer,min;
	min=(k<n-k)? k:n-k;
	answer=fact(n,n-min)/fact(min,0);
	return answer;
}
main()
{

	int i,j,total=0,dif=0,max=pow(10,6);
	int start=23,end=100;
	//number of possibilities
	for(i=start;i<=end;i++) total+=(i+1);
	//eliminite the numbers <=10^6
	for(i=1;i<=5;i++)
	{
		for(j=0;j<=i;j++)
		printf("%d ",C(j,i));
		printf("\n");
	}
	for(i=start;i<=end;i++)
	{
		dif=0;
		for(j=0;j<ceil(i/2)+1;j++)
		{
			
			if(C(j,i)<=max) dif+=2;
			else break;
				
		}
		total-=dif;
	}
	printf("\nnumber of C(n,r) greatet than 10^6 :%d",total);	
}
