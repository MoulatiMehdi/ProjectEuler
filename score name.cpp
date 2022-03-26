#include<stdio.h>
#include<string.h>
//function to reverse order if tab1>tab2
void compare_name(char *tab1,char *tab2)
{
	char copy[20];
	if(strcmp(tab1,tab2)>0)
	{
		strcpy(copy,tab1);
		strcpy(tab1,tab2);
		strcpy(tab2,copy);		
	}
}
main()
{
	char tab[6000][20];
	char c;
	FILE * file;
	file=fopen("names.txt","r");
	int i,j;
	//get the names from the file
	for(i=0;c!=EOF;i++)
	{	
		for(j=0;;j++)
		{	
			c=fgetc(file);
			if(c==','||c==EOF)break;
			else if(c!='"')	tab[i][j]=c;
			else j--;			
		}		
	}
	
	int max=i; //number of names in the file
	
	//names in order 
	for(i=0;i<max;i++)
	for(j=i+1;j<max;j++) compare_name(tab[i],tab[j]);		
		
	int num[max]={0};
	long sum=0;
	//calculate the score
	for(i=0;i<max;i++)
	{
		for(j=0;tab[i][j]!='\0';j++)
		{
			num[i]+=tab[i][j]-'A'+1;	
		}
		sum+=num[i]*(i+1);	
	}
	printf("%ld is the sum of scores names",sum);	
}
