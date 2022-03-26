#include<stdio.h>
#include<math.h>
double long S(double r)
{
	long double answer=0;
	int n=5000;
	while(n!=0)
	{
		answer+=(900-3*n)*pow(r,n-1);
		n--;
	}
	return answer;
}
main()
{
	double long  k=0.1;
	for(long double i=1;i<100;i+=k)
	{
		double long answer=S(i);
		if((long long)answer==-600000000000)
		{
			printf("%.12f\n",(double)i);
			break;
		}
		
		if(answer<-600000000000)
		{
			i-=k;
			k/=10;
			
		}
	}
}
