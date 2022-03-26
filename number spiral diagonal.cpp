#include<stdio.h>
#include<math.h>
main()
{
	int max=1001;
	long num[max]={0};//(impair number)^2 
	long dgnl[max+max-1];//numbers in diagonal
	dgnl[0]=1;
	int i,j,k=0;//counter
	long sum=0;//final answer
	for(i=1,j=0;i<=max;j++,i=i+2)
	{
		num[j]=pow(i,2);
		while(dgnl[k]<num[j])
		{
			dgnl[k+1]=dgnl[k]+i-1;//calculate the numbers in diagonal
			k++;
		}		
	}
	for(i=0;i<=k;i++) sum+=dgnl[i]; //calculate the sum			
printf("------->sum=%ld",sum);//print the answer	
}
