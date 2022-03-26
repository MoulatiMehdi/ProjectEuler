#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define int_big long long//just want to name it like that 
int num_digit(unsigned int num)
//number of digit of a number num must be bigger than 0 num>0
{
	return ceil(log(num+1)/log(10));
	
}

int*cpy_line(int*tab,int max,int k)
//copy a line and multiplay it by k (max is number of digit)
{
	int *line=(int*)calloc(max,sizeof(int));
	for(int_big i=0;i<max;i++)
	{
		line[i]=tab[i]*k;
	}
	return line;
}
unsigned int_big S(int_big p1,int_big p2)       //p2>p1
{
	int max=num_digit(p1),cp2=p2;	           //we need p2 later
	int result[max]={0};                     //we will fill it by the p1 digit
	int **M=(int**)calloc(max,sizeof(int*));//a matrix  contient p2 digit
	int *line;//the array that we will use to mins line M[i] from other line
	int k=0,i=0,j,num=0;
	
	M[max-1]=(int*)calloc(max,sizeof(int));
	while(p1!=0)
	{
		M[max-1][max-i-1]=cp2%10;//fill the last line (because it contient all digit of p2)
		result[i]=p1%10;
		
		cp2/=10;
		p1/=10;
		i++;
	}
	
	for(i=max-2;i>=0;i--)
	//fill the rest of the lines 
   //(delete the first digit from the M[i] and the rest in M[i-1])
	{
		M[i]=(int*)calloc(max,sizeof(int));
		for( j=0;j<=i;j++)
		{
			M[i][j]=M[i+1][j+1];
		}
	}
	
	for(i=0;i<max;i++)
	{
		
		
		result[i]-=k;
		k=0;
		while(result[i]<0||result[i]%M[i][i]!=0)
		//add 10 until M[i][i] divide result[i]
		{
			result[i]+=10;
			k++;
		}
		
		result[i]/=M[i][i];
		M[i][i]=1;
		
		num+=result[i]*pow(10,i);//we find the a digit from the answer
		for(j=i+1;j<max;j++)
		//solving  the matrix 
		{
			line=cpy_line(M[i],max,M[j][i]);
			
			result[j]*=M[i][i];
			result[j]-=result[i]*M[j][i];
			
			M[j]=cpy_line(M[j],max,M[i][i]);
			
			for(int_big k=i;k<max;k++)
			{
				M[j][k]-=line[k];
			}	
		}	
	}
	return num*p2;//this is the number that we looking for
}

main()
{
	int  limit=1000000;
	int  *prime=(int *)calloc(limit+100,sizeof(int ));//prime number 
	int  *T=(int *)calloc(limit+100,sizeof(int ));//is_prime(i)
	int i,j;
	//finding the prim numbers
	//primes number have 0
	//the rest have 1
	//this method is the fast method to find primes number 
	for(i=3;i<=sqrt(limit+100);i+=2)
	{
		if(!T[i])
		{
			j=i;
			while(i*j<=limit+100)
			{
				T[i*j]=1;
				j++;
			}
		}
	}
	j=0;
	for(i=5;i<limit+100;i+=2)
	{
		if(!T[i])//prime number i have 0 in T[i]
		{	
			prime[j]=i;
			j++;
		}
	}
	unsigned int_big answer=0;
	for(i=0;prime[i]<=limit;i++)
	{
		int_big p1=prime[i];
		int_big p2=prime[i+1];
		answer+=S(p1,p2);
	}
	printf("%llu",answer);
}

