#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long double sum(long double q)
{
	long double answer;
	answer=1+pow(q,11);
	answer/=1+q;
	return answer;
}
long double  **matrix(int n)
{
	long double ** tab=(long double**)calloc(n,sizeof(long double*));
	for( int i=0;i<n;i++)
	{
		tab[i]=(long double*)calloc(n,sizeof(long double));
		for( int j=0;j<n;j++)
		{
			tab[i][n-j-1]=pow(i+1,j);
		}
	}
	return tab;
}

long double* solve_matrix(long double **tab,long double*tab1,int n)
{
	long double a=0;
	int i,j,k;
	long double*answer=(long double*)calloc(n,sizeof(long double));
	for(i=0;i<n;i++)
	{
		answer[i]=tab1[i];
	}
	
	for(i=0;i<n;i++)
	{
		long double line[n]={0};
		
		for(j=0;j<n;j++)
		{
			line[j]=tab[i][j]/(long double)tab[i][i];
		}
		for(j=i+1;j<n;j++)
		{	
			a=tab[j][i];
			for(k=i;k<n;k++)
			{
				tab[j][k]-=line[k]*a;
			}	
			answer[j]-=a*answer[i]/(long double)tab[i][i];	
		}
			
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=i-1;j>=0;j--)
		{
			a=tab[j][i];
			for(k=0;k<n;k++)
			{
				tab[j][k]-=tab[i][k]*a/(long double)tab[i][i];
			}
			answer[j]-=a*answer[i]/(long double)tab[i][i];
		}
		if(tab[i][i]!=0)
		{
			answer[i]/=(long double)tab[i][i];
			tab[i][i]/=(long double)tab[i][i];
		}
	}
	return answer;
}

main()
{
	int max=10;
	long double** tab;
	long double *answer=NULL;
	long double *num=(long double*)calloc(max,sizeof(long double));
	
	for(int i=1;i<=max;i++)
	{
		num[i-1]=sum(i);
	}
	
	long double sum=0,k,l;
	
	for(int  j=1;j<=max;j++)
	{
		tab=matrix(j);
		answer=solve_matrix(tab,num,j);
		k=0;
		l=0;
		for(int i=0;i<j;i++)
		{
			k+=(long double)answer[i]*pow(j+1,j-i-1);
			l+=(long double)answer[i]*pow(j,j-i-1);
		}
		if(k-(long long)k>0.5) k=ceil(k);
		else  k=floor(k);
		__mingw_printf ("FIT %d:OP(%d,n)=%.0Lf\n",j,j+1,k);
		sum+=k;
	}
	__mingw_printf("\n--->%.0Lf",sum);
	
	
	
}
