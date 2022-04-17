#include<stdio.h>
#include<conio.h>
#include<math.h>
main()
{
	FILE*file;
	file=fopen("p099_base_exp.txt","r");
	
	int base[1000][2]={0};
	int i=0,j=0;
	
	char c;
	
	double log_base[1000]={0};
	double max_product=0;
	
	while((c=fgetc(file))!=EOF)
	{
		if(c==',')
		{
			
			j++;
		}
		else if(c=='\n')
		{
		
			i++;
			j=0;
		}
		else
		{
			base[i][j]*=10;
			base[i][j]+=c-'0';
		}
	}

	for(i=0;i<1000;i++) 
	log_base[i]=log(base[i][0]);
	
	for(i=0;i<1000;i++)
	{
		if(max_product<log_base[i]*base[i][1])
		{
			max_product=log_base[i]*base[i][1];
			j=i+1;
		}
	}
	printf("%d",j);
}
