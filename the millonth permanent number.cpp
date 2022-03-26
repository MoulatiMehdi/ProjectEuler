#include<stdio.h>
#include<string.h>
long fact(int a) //calculate all the probabelities
{
	int i;
	long fact=1;
	if(a==0) fact=1;
	else for(i=1;i<=a;i++) fact*=i;
	
	return fact;
}

char choose_char(int a,char*tab)//choose then eliminete the character from an array 
{
	char c=tab[a];
	
	unsigned  i;
	for(i=a;i<strlen(tab);i++)
	{
		tab[i]=tab[i+1];	
	}
	
	return c;
}
main()
{
	char string[]="0123456789";//the digit that we have in the probelm
	char answer[10];           //the final answer
	long tab=1000000;         //the clasification of the lexicographic permutation
	long test;
	int i,j,k=0,max=10;
	
	for(i=9;i>=0;i--)
	{
		for(j=1;j<=max;j++)
		{
			test=fact(i)*j;
			if(test>=tab)
			{	
				anwser[k]=choose_char(j-1,string);
				k++;
				tab-=fact(i)*(j-1);
				break;
			}		
		}			
	}
	printf("%s",answer);	
}
