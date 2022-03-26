#include<stdio.h>
#define int_64bit unsigned long long

 int_64bit C(int n,int k)
 {
 	double  answer=1;
 	int max,min;
 	
 	if(k>n-k) max=k,min=n-k-1;
 	else max=n-k+1,min=k;
 	
 	while(min!=0)
 	{
 		answer*=max;
 		answer/=(double)min;
 		max++;
 		min--;
	}
 	return answer;
 	
 }
main()
{
	double sum=0;
	
	
	sum=1.0-C(60,20)/(double)C(70,20);
	sum*=7;
	printf("--->%.9f",sum);
}
