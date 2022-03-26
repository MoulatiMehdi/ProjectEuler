#include<stdio.h>
#include<stdlib.h>
int max=17;
void check_tab(int*tab,int*tab1)
{
	int i=max-1;
	int j;
	while(tab[i]==0&&tab1[i]==0) i--;
	if(i>=15)
	{
		j=0;
		while(j<=15)
		{
			tab[j]=tab[i-15];	
			tab1[j]=tab1[i-15];
			j++;
			i++;
		}
		for(j=max-1;j>=16;j--)
		{
			tab[j]=0;
			tab1[j]=0;
		}	
	}
}
is_L9DP(int*tab)//is last 9 digit are pandigit
{
	int answer=1,check;
	for(int k=1;k<=9;k++)
	{
		check=0;
		for(int j=0;j<9;j++) if(tab[j]==k) check++;	
		if(check!=1)
		{
			answer=0;
			break;
		}
	}	
	return answer;
}

int* sum(int*a,int *b,int n)
{
	int*sum=(int*)calloc(max,sizeof(int));
	
	if(n==1)check_tab(a,b);//n used for turn on/off the function 
	for(int i=0;i<max;i++)
	{
		sum[i]+=a[i]+b[i];
		if(sum[i]>=10)
		{
			sum[i+1]+=sum[i]/10;
			sum[i]%=10;
		}
	}
	return sum;
}

is_F9DP(int*tab)//is first 9 digit are pandigit
{
	int answer=1,check;
	int i=max-1;
	while(tab[i]==0)i--;
	
	for(int k=1;k<=9;k++)
	{
		check=0;
		for(int j=i;j>=i-8;j--) if(tab[j]==k) check++;	
		if(check!=1)
		{
			answer=0;
			break;
		}
	}	
	return answer;
}
main()
{
int *tab=(int*)calloc(max,sizeof(int));
	
	int*b=(int*)calloc(max,sizeof(int));
	int*a=(int*)calloc(max,sizeof(int));
	a[0]=1;
	b[0]=1;
	
	int *tab1=(int*)calloc(max,sizeof(int));
	int*c=(int*)calloc(max,sizeof(int));
	int*d=(int*)calloc(max,sizeof(int));
	c[0]=1;
	d[0]=1;
		
	for(int i=3;;i+=3)
	{
		tab1=sum(c,d,1);
		tab=sum(a,b,0);
		if(is_L9DP(tab)&&is_F9DP(tab1))
		{
			printf("the answer is : %d",i);
			break;
		}
		c=sum(d,tab1,1);
		a=sum(b,tab,0);
		if(is_L9DP(a)&&is_F9DP(c))
		{
			printf("the answer is : %d",i+1);
			break;
		}
		d=sum(tab1,c,1);
		b=sum(tab,a,0);
		if(is_L9DP(b)&&is_F9DP(d))
		{
			printf("the answer is : %d",i+2);
			break;
		}
	}
}
