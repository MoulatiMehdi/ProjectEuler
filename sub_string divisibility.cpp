#include<stdio.h>
#include<math.h>
#include<string.h>
int fact(int a)
{
	int i,answer=1;
	for(i=1;i<=a;i++)
	{
	 answer*=i;	
	}
	return answer;
}
main()
{
	int   i,j,l,n,k=0;
	unsigned long long num=0,div[7];
	int  test=0,clas;
	int prime[7]={2,3,5,7,11,13,17};
	
	char tab[]="0123456789";
	char answer[10];
	
	for(n=1+fact(6)*1;n<=fact(10);n++)
	{
		clas=n;
		k=0;
		for(i=9;i>=0;i--)
		{
			for(j=1;j<=10;j++)
			{
				if(fact(i)*j>=clas) 
				{
				answer[k]=tab[j-1];
				k++;
				for(l=j-1;l<10-k;l++) tab[l]=tab[l+1];	
					
					tab[10-k]='\0';	
					clas-=fact(i)*(j-1);
					break;			
				}
			}	
		}
		answer[k]='\0';
		for(i=0;i<7;i++)
		{
			div[i]=(answer[i+1]-'0')*100+(answer[i+2]-'0')*10+(answer[i+3]-'0');
			if(div[i]%prime[i]==0)test++;
		}
		if(test==7) 
		{	
			num+=(answer[0]-'0')*pow(10,9)+div[0]*pow(10,6)+div[3]*pow(10,3)+div[6];
		}
		test=0;	
		strcpy(tab,"0123456789");	
	}	
printf("the sum is : %lld",num);	
}
