#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int t_n(int a)
{
	int i,num=0,test=0;
	
	for(i=1;i<=a;i++)
	{
		num=((i)*(i+1))/2;
		if(num==a)
		{
		test=i;
		break;
		} 
		else if(num>a) break;		
	}
	return test;
}
main()
{
	int i,j,num=0,total=0;;
	char c;
	FILE* file;
	file=fopen("words.txt","r");
	for(i=0;;i++)
	{
		num=0;
		while((c=fgetc(file))!=','&&c!=EOF)
		{
			if(isalpha(c)) num+=c-'A'+1;	
			
			else continue;
		}
		if(t_n(num)!=0) 
		{
			total++;
			
		 } 
		if(c==EOF)break;
	}
	printf("the total is %d",total);
}
