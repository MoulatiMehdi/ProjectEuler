//hangarian algorithm
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Max(a,b) (a>b)?a:b
 int line=15;
int**M;
int**tmp;
row_max(int**tab,int row)
{
	int max=tab[row][0];
	for(int j=0;j<line;j++)
	{
		max=Max(max,tab[row][j]);
	}
	return max;
}
colon_max(int**tab,int colon)
{
	
	int max=tab[0][colon];
	for(int i=0;i<line;i++)
	{
		max=Max(max,tab[i][colon]);
	}
	return max;
}

int** cpy(int **source)
{
	int **copy=(int**)calloc(line,sizeof(int*));
	for(int i=0;i<line;i++)
	{
		copy[i]=(int*)calloc(line,sizeof(int));
		for(int j=0;j<line;j++)
		{
			copy[i][j]=source[i][j];
		}
	}
	return copy;
}

void mins(int**tab)
{
	
	int max_i=0,max_j=0;
	int i,j;
	for( i=0;i<line;i++)
	{
		max_i=row_max(tab,i);
		if(max_i==0)continue;
		for(j=0;j<line;j++)
		{
			tab[i][j]-=max_i;
		}
	}
	for( j=0;j<line;j++)
	{
		max_j=colon_max(tab,j);
		if(max_j==0)continue;
		for(i=0;i<line;i++)
		{
			tab[i][j]-=max_j;
		}
	}

}



int ns_row(int** tab,int row,int n)
{
	int answer=0;
	for(int i=0;i<line;i++)
	{
		if(tab[row][i]==n)answer++;
	}
	return answer;
	
}

int ns_colon(int** tab,int colon,int n)
{
	int answer=0;
	for(int i=0;i<line;i++)
	{
		if(tab[i][colon]==n)answer++;
	}
	return answer;
}
int**B_0(int **tab)
//1-->cellule covered by 1  line coverd
//2-->cellule covered by 2  line coverd
//9 uncovered cellule
{
	int **test=(int**)calloc(line,sizeof(int*));
	int i,j;
	
	for(i=0;i<line;i++)
	{
		test[i]=(int*)calloc(line,sizeof(int));
		for(j=0;j<line;j++)
		{
			if(tab[i][j]!=0) test[i][j]=9;
		}
	}
	
	for(i=0;i<line;i++)
	{
		
		for(j=0;j<line;j++)
		{
			
			if(test[i][j]==0) 
			{
				int max_i=ns_row(test,i,0);
				int max_j=ns_colon(test,j,0);
				
				if(max_j>max_i)
				{
					int k=0;
					while(k!=line)
					{
						if(test[k][j]>=9)test[k][j]=1;
						else test[k][j]+=1;
						k++;
					}
				}
				else if(max_j<max_i)
				{
					int k=0;
					while(k!=line)
					{
						if(test[i][k]>=9)test[i][k]=1;
						else test[i][k]+=1;
						k++;
					}
				}		
			}
		}
	}
	
	for(i=0;i<line;i++)
	{
		
		for(j=0;j<line;j++)
		{
			
			if(test[i][j]==0) 
			{
				
				int k=0;
				while(k!=line)
				{
					if(test[k][j]>=9)test[k][j]=1;
					else test[k][j]+=1;
					k++;
				}
				
					
			}
		}
	}
	return test;
}
void eliminate(int**tab)
{
	int**test=B_0(tab);
	int max=0;
	int i,j;
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			if(test[i][j]!=9)continue;
			if(max==0)max=tab[i][j];
			else max=Max(max,tab[i][j]);
		}	
	}	
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			if(test[i][j]==1)continue;
			
			if(test[i][j]==9)
			{
				tab[i][j]-=max;
			}
			else
			{
				tab[i][j]+=max;
			}
		}	
	}
}
int check(int**tab)
{
	int**test=B_0(tab);
	for(int i=0;i<line;i++)
	{
		if(ns_row(test,i,9))
		{
			return 0;
		}
	}
	return 1;
}
int colones[15]={0};
int max=0;
solve(int k,int value)
{
	
	if(k==line)
	{
		max=Max(max,value);
		return max;
	}
	int n=0;
	int c=0;
	for(int i=0;i<line;i++)
	{
		if(tmp[k][i]!=0&&n==0)
		{
			c++;
			if(c==line-1) 
			{
				n++;
				i=-1;
			}
			continue;
		}
		int test=0;
		for(int j=0;j<k;j++)
		{
			if(i==colones[j])
			{
				test=1;
				break;
			}
		}
		if(test==1)continue;
		colones[k]=i;
		max=solve(k+1,value+M[k][i]);
	}
	return max;
}
main()
{
	M=(int**)calloc(line,sizeof(int*));
	M[0]=(int*)calloc(line,sizeof(int));
	
	FILE*file;
	file=fopen("matrix.txt","r");
	char c;
	int i=0,j=0;
	
	while((c=fgetc(file))!=EOF)
	{
		
		if(c>='0'&&c<='9')
		{
			while(c>='0'&&c<='9')
			{	
				M[i][j]*=10;	
				M[i][j]+=c-'0';
				c=fgetc(file);	
			}
			j++;
		}
		if(c=='\n')
		{
			i++;
			M[i]=(int*)calloc(line,sizeof(int));
			j=0;
		}	
	}
	line=i+1;
	tmp=cpy(M);
	mins(tmp);
	while(!check(tmp))
	{
		eliminate(tmp);
	}
	printf("\n--->%d",solve(0,0));
}
//best solution
/*
#include <stdio.h>
#include <string.h>

int mat[15][15];
int dp[32768];
int bc[32768];

int main() {
  FILE *f=fopen("matrix.txt","r");
  int i,j,k,cur;
  for(i=0;i<15;i++) for(j=0;j<15;j++) fscanf(f,"%d",&mat[i][j]);
  fclose(f);
  bc[0]=0;
  for(i=1;i<32768;i++) bc[i]=(i&1)+bc[i>>1];
  memset(dp,0,sizeof(dp));
  for(i=0;i<32768;i++) for(k=0;k<15;k++) if(!(i&(1<<k))) {
    cur=dp[i]+mat[bc[i]][k];
    if(dp[i+(1<<k)]<cur) dp[i+(1<<k)]=cur;
  }
  printf("%d\n",dp[32767]);
  return 0;
}
*/
