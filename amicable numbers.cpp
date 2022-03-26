#include<stdio.h>
int d(int number)
{
	int i,sum_1=0,sum_2=0;
	int num=number;
	
	for(i=1;i<num;i++) if(num%i==0) sum_1+=i;
	
	num=sum_1;
	
	for(i=1;i<=num/2;i++) if(num%i==0) sum_2+=i;	
			
	
	int test;
	if(number==sum_2&&sum_1!=sum_2) 
	{
	 test=1;
	 printf("the numbers %d and %d are amicable\n",sum_2,sum_1);
	}
	else test=0;
	return test;
}
main()
{
	int i,max,totale=0;
	int test=0;
	printf("search for the amicable numbers\n\tfrom 1 to ");
	scanf("%d",&max);
	for(i=0;i<max;i++)
	{
		test=d(i);
		if(test==1) totale+=i;		
	}
	printf("the sum of all amicable numbers under %dis :%d",max,totale);	
}
