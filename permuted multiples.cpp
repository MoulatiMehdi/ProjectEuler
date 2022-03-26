#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int num_digit(int a)
{
	int i=1;
	for(i=1;pow(10,i)<=a;i++) continue;
	return i;
}
int *split_num_digit(int a)
{
	int max=num_digit(a),i,test;
	int *tab=(int*)malloc(sizeof(int)*max);
	test=a;
	for(i=0;i<max;i++)
	{
		tab[i]=test/pow(10,max-i-1);
		test-=tab[i]*pow(10,max-i-1);	
	}
	return tab;	
}
int is_same_digit(int num1,int num2)
{
	
	int max2,max1,i,j,answer=1,test;
	int *tab1,*tab2;
	max1=num_digit(num1);
	max2=num_digit(num2);
	tab2=split_num_digit(num2);
	tab1=split_num_digit(num1);
	
	for(i=0;i<max1;i++)
	{
		if(max1!=max2)
		{
			answer=0;
			break;
		}
		for(j=i+1;j<max2;j++)
		{
			if(tab1[j]<tab1[i])
			{
				test=tab1[i];
				tab1[i]=tab1[j];
				tab1[j]=test;			
			}
			if(tab2[j]<tab2[i])
			{
				test=tab2[i];
				tab2[i]=tab2[j];
				tab2[j]=test;	
			}
		}
		if(tab2[i]!=tab1[i]) 
		{
			answer=0;
			break;
		}
	}
	
	return answer;
}
main()
{
	int i,j,test;
	for(i=1;i<1000000;i++)
	{
		test=0;
		for(j=2;j<=6;j++)
		{
			if(is_same_digit(i,i*j))
			{
				test++;
			 } 
			 else break;	
		}
		if(i==int(pow(10,num_digit(i))/6))
		{
			i=pow(10,num_digit(i));
	
		 } 
		if(test==5) 
		{
			printf("\nthe smallest integer contain the same digits : %d",i);
			break;
		}
	}		
}
