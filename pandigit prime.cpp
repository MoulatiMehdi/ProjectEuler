#include<stdio.h>
#include<math.h>
int num_digit(int a)
{
	int i=1;
	for(i=1;pow(10,i)<=a;i++)continue;
	return i;	
}
int test_digit(int * tab,int a)
{
	int i,j,max=num_digit(a),test1=0,test2;
	for(i=0;i<max;i++)
	
	{//testing if each   digits are diffrence  of the number a
		for(j=i+1;j<max;j++)
		{
			if(tab[j]==tab[i]||tab[j]==0) 
			{
				test1++;
				break;
			}
		}
		if(test1!=0) break;	
		test2=0;
		//testing if they are pandigit from 1 to n
		for(j=0;j<max;j++)
		{
			
				if(tab[j]==i+1) 
			{
				test2++;
				if(test2!=1)break;
			}
		}
		if(test2!=1)break;
	}
	if(test1!=0||test2!=1) test1=0;
	else test1=1;	
	return test1;
}
int is_prime(int a)
{
	int i,test=1;
	for(i=2;i<=sqrt(a);i++)
	{
		if(a%i==0) test=0;
	}
	return test;
	
}
main()
{
	int i,j=0,num,max_digit;
	
	int tab[9];
	
	
	for(i=7999999;i>0;i--)
	{
		if(is_prime(i)!=1) continue;
		
		max_digit=num_digit(i);
		num=i;
		
		for(j=0;j<max_digit;j++)
		{
			tab[j]=num/pow(10,max_digit-j-1);
			num-=tab[j]*pow(10,max_digit-j-1);		
		}
		
		if(test_digit(tab,i))
		{
			printf("%d\t",i);
			break;
			
		 } 		
	}
}

