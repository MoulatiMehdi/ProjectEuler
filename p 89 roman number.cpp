#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
roman_num_trans(char c)
{
	int num=0;
	switch(c)
	{
		case 'I':num= 1;break;
		case 'V':num= 5;break;
		case 'X':num= 10;break;
		case 'L':num= 50;break;
		case 'C':num= 100;break;
		case 'D':num= 500;break;
		case 'M':num= 1000;break;
	}
	return num;
}
num_roman_char(int num)
{
	int answer=0;
	
	for(int i=2;i>=0;i--)
	{
		if(num>=pow(10,i+1))answer+=num/pow(10,i+1),num%=(int)pow(10,i+1);
		if(num>=9*pow(10,i)) answer+=2,num-=9*pow(10,i); 
		if(num>=5*pow(10,i)) answer+=1,num-=5*pow(10,i);
		if(num>=4*pow(10,i)) answer+=2,num-=4*pow(10,i);
	}
	answer+=num;
	return answer;
}
main()
{
	FILE*file=fopen("p089_roman.txt","r");
	
	int **tab=(int**)calloc(1000,sizeof(int*));
	
	tab[0]=(int*)calloc(20,sizeof(int));
	int* answer=(int*)calloc(1000,sizeof(int));
	
	int sum=0;
	int i=0,j=0,num=0;
	
	char c;
	
	while((c=fgetc(file))!=EOF)
	{
		
		if(c=='\n')
		{
			j=0;
			i++;
			tab[i]=(int*)calloc(20,sizeof(int));
		}
		else
		{
			num++;
			tab[i][j]=roman_num_trans(c);
			j++;
		}
		
	}
	
	for(i=0;i<1000;i++)
	{

		for(j=0;tab[i][j]!=0;j++)
		{
			if(tab[i][j]<tab[i][j+1])	answer[i]-=tab[i][j];
			else answer[i]+=tab[i][j];
		}
		
		sum+=num_roman_char(answer[i]);
	}
	printf("the answer is :%d\n",num-sum);
	
}
