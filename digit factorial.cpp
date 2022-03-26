#include<stdio.h>
#include<math.h>
#include<conio.h>

int fact(int a)//factorizing the number a (a!)
{
	int i,answer=1;
	if(a<0) printf("ERROR,this number is under 0");
	else
	{
		for(i=1;i<=a;i++)
		{
			answer*=i;
		}
	}
	return answer;
}
int num_digit(int a)//number of digits
{
	int i;
	for(i=1;;i++)
	if(pow(10,i)>a)break;
	return i;
}
main()
{
	int i,j,max_digit,num,sum=0,test=1;
	int tab[7];//digits
	for(i=3;num_digit(i)<=5;i++)
	{
		max_digit=num_digit(i);
		num=i;
		test=0;
		for(j=0;j<max_digit;j++)
		//divide the number to digits
		{
			tab[j]=num/pow(10,max_digit-1-j);
			num-=tab[j]*pow(10,max_digit-1-j);	
			test+=fact(tab[j]);
		}
		if(i==test) // print the result
		{
			for(j=0;j<max_digit;j++)
			{
				printf("%d!",tab[j]);
				if(j<max_digit-1)printf("+");
				else printf("=%d",i);
				
			}
			sum+=i;
			printf("\n");		
		}		
	}
	printf("\n sum=%d\n",sum);	
}
