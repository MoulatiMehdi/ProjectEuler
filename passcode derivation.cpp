#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int fact(int num)
{
	int i=1;
	while(num>=1)
	{
		i*=num;
		num--;
	}
	return i;
}
int* generateur_code(int classe)
//permutation of numbers 01236789
{
	 char string[]="01236789";
	 int *answer=(int*)calloc(8,sizeof(int));
	int i,j,k=0,l=0;
	for(i=7;i>=0;i--)
	{
		for(j=1;j<=8;j++)
		{
			if(classe<fact(i)*j)
			{
				
				answer[k]=string[j-1]-'0';
				classe-=fact(i)*(j-1);
				k++;
				l=j;
				while(l<8)
				{
					string[l-1]=string[l];
					l++;
				}
				break;
			}
		}
	}
	return answer;
}
main()
{
	int tab[50]={0};
	int i=0,j=0,test;
	FILE* file;
	
	file=fopen("p079_keylog.txt","r");
	char c;
	while((c=fgetc(file))!=EOF)
	{
		if(c=='\n') 
		{
			test=0;
			for(j=0;j<i;j++) if(tab[j]==tab[i])test++;
			
			if(test==0)	i++;
			else tab[i]=0;

		}
		else
		{
			tab[i]*=10;
			tab[i]+=c-'0';
		}
	}	
	int max=i,code[max][3]={0};
	for(i=0;i<max;i++)
	{
		code[i][0]=tab[i]/100;
		code[i][1]=(tab[i]-code[i][0]*100)/10;
		code[i][2]=tab[i]-code[i][0]*100-code[i][1]*10;
	}
	
	int*answer=(int*)calloc(8,sizeof(int));
	
	for(i=fact(8)-1;i>=0;i--)
	{
		answer=generateur_code(i);
		test=0;
		for(j=0;j<max;j++)
		{	
			int l=0;			
			for(int k=0;k<8;k++)
			{
				if(code[j][l]==answer[k]) 
				{
					test++;
					l++;
				}
			}
			if(l!=3) break;
		}
		if(test>=max*3)break;
	}
	printf("the answer is :");
	for(int k=0;k<8;k++) printf("%d",answer[k]);
	
	
}
