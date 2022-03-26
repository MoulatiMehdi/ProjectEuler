#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
int max;
char p[16][10];
int char_T[100]={0};
char tab[100][16];
char *key=(char*)calloc(16,sizeof(char));
int test_row(int i,int k)
{
	int check=0;
	for(int j=0;j<k;j++)
	{
		if(tab[i][j]==key[j])check++;
	}

	return check;
}

int test(char*key)
{
	for(int i=0;i<max;i++)
	if(test_row(i,16)!=char_T[i])
	return 0;
	
	return 1;
	
}

void solve(int k)
{
	if(k==16)
	{
		
		if(test(key)) 
		{
			printf("%s:",key);
			printf("-->true");
			printf("\n");
			exit(1);
		}
		return ;
	}
	else
	for(int i=0;p[k][i]!='\0';i++)
	{
		int check=0;
		for(int j=0;j<max;j++)
		{
			if(test_row(j,k)>char_T[j]) 
			{
				check++;
				break;
			}
		}
		if(check!=0)continue;
		key[k]=p[k][i];
		solve(k+1);
	}
	
}
main()
{
	
	
	
	FILE*file=fopen("p185.txt","r");
	char c;
	int i=0,j=0,k=0;
	while((c=fgetc(file))!=EOF)
	{
		
		if(isdigit(c))
		{
			tab[i][j]=c;
			j++;
		}
		else
		{
			if(c==';')
			{
				c=fgetc(file);
				char_T[i]=c-'0';
			
			}
			else if(c=='\n') 
			{
				tab[i][j]='\0';
				i++;
				j=0;
			}
		}
	}
	max=i;
	
	

	

	for(i=0;i<max;i++)
	{
		if(char_T[i]==0)
		{
			for(j=0;j<max;j++)
			{
				for(k=0;k<16;k++)
				{
					if(tab[i][k]==tab[j][k]&&j!=i)tab[j][k]='F';
				}
			}
			
			for(k=0;k<16;k++)
			{
				tab[i][k]='F';
			}
		}
	}
	int max_n=0;
	k=0;
	for(i=0;i<16;i++)
	{
		max_n=0;
		for(j=0;j<max;j++)
		{
			int test=0;
			for(k=0;k<max_n;k++)
			{
				if(tab[j][i]==p[i][k]) 
				{
					test++;
					break;
				}
			}
			if(test==0&&isdigit(tab[j][i]))
			{
				p[i][max_n]=tab[j][i];
				max_n++;
				
			}
		}
		p[i][max_n]='\0';
	}
	
	
	/*for( i=0;i<16;i++)
	{
		for( j=0;p[i][j]!='\0';j++)
		{
		 	printf("%c ",p[i][j]);
		}
		printf("-->%d\n",j);
	}*/
	solve(0);
	
	
	
	
}
