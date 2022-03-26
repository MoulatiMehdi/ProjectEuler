#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
unsigned int digit_num(int num)
{
	return floor(log(num)/(double)log(10))+1;
}
remarkable(int num,int num1)
{
	
	int digit[10]={0};
	int digit1[10]={0};
	if(digit_num(num)!=digit_num(num1)) return 0;
	else
	{
		int answer=1;
		while(num!=0)
		{
			digit[num%10]++;
			num/=10;
			
			digit1[num1%10]++;
			num1/=10;
		}
		for(int i=0;i<10;i++)
		{
			if(digit[i]!=digit1[i])
			{
				answer=0;
				break;
			}
		}
		return answer;
	}
	
}
int check_tab(char*tab,char*tab1)
{
	char test[14];
	char test1[14];
	strcpy(test,tab);
	strcpy(test1,tab1);
	int answer=1;
	char c;
	for(int i=0;test[i]!='\0';i++)
	{
		for(int j=i+1;test[j]!='\0';j++)
		{
			if(test[i]>test[j])
			{
				c=test[i];
				test[i]=test[j];
				test[j]=c;
			}
		}
		for(int j=i+1;test1[j]!='\0';j++)
		{
			if(test1[i]>test1[j])
			{
				c=test1[i];
				test1[i]=test1[j];
				test1[j]=c;
			}
		}
		if(test[i]!=test1[i])
		{
			answer=0;
			break;
		}
	}

	return answer;
}
is_equal(int num ,char* tab,char*tab1)
{
	int digit[digit_num(num)]={0};
	unsigned int i=digit_num(num)-1,j;
	while(num!=0)
	{
		digit[i]=num%10;
		num/=10;
		i--;
	}
	
	int string_num[30]={0};
	for(i=0;i<strlen(tab);i++)
	{
		char c=tab[i];
		string_num[c-'A']=digit[i];		
	}
	int test=1;
	for(i=0;i<strlen(tab);i++)
	{

		for( j=i+1;j<strlen(tab);j++)
		{
			if(tab[i]==tab[j])continue;
			else
			{
				if(string_num[tab[i]-'A']==string_num[tab[j]-'A'])
				{
						test=0;
						break;
				}
			}
		}
		
		if(test==0)break;
	}
	if(test==1)
	{		
		num=0;
		i=0;
		
		for(i=0;i<strlen(tab1);i++)
		{
			char c=tab1[i];
			
			num*=10;
			num+=string_num[c-'A'];
			
		}
		int a=sqrt(num);
		if(a*a==num&&string_num[tab1[0]-'A']!=0)test=num;
		else test=0;
	}
	else test=0;
	
	return test;
	
}

main()
{
	FILE* file=fopen("p098_words.txt","r");
	char** tab=(char**)calloc(2000,sizeof(char*));
	char c;
	
	unsigned int i=0,j=0;
	unsigned int max=i;
	int max_num=0;
	unsigned int num;
	unsigned int max_square;
	
	
	int n=0;
	
	tab[i]=(char*)calloc(50,sizeof(char));
	while((c=fgetc(file))!=EOF)
	{
		
		if(c=='"') continue;
		else if(c==',')
		{
			i++;
			j=0;
			tab[i]=(char*)calloc(50,sizeof(char));
		}
		else
		{
			tab[i][j]=c;
			j++;
		}
	}
	max=i;
	
	char ***anagram=(char***)calloc(max,sizeof(int**));
	unsigned int max_digit=0;
	for(i=0;i<max;i++)
	{
		
		for(j=i+1;j<max;j++)
		{
			if(strlen(tab[i])!=strlen(tab[j]))continue;
			if(check_tab(tab[i],tab[j]))
			{
				
				if(strlen(tab[i])>max_digit)max_digit=strlen(tab[i]);
				
				anagram[n]=(char**)calloc(2,sizeof(int*));	
				anagram[n][0]=(char*)calloc(14,sizeof(int*));	
				anagram[n][1]=(char*)calloc(14,sizeof(int*));	
				strcpy(anagram[n][0],tab[i]);
				strcpy(anagram[n][1],tab[j]);
				n++;
			}
		}	
	}
	max=n;
	max_square=sqrt(pow(10,max_digit));
	int square[max_square]={0};
		
	for(i=1;i<max_square;i++)
	{
		square[i]=pow(i,2);
	}
	n=0;
	
	for(i=0;i<max;i++)
	{
		printf("\n%s %s:\n",anagram[i][0],anagram[i][1]);
		for(j=sqrt(pow(10,strlen(anagram[i][0])-1));j<max_square&&digit_num(square[j])==strlen(anagram[i][0]);j++)
		{
			
			 if(digit_num(square[j])==strlen(anagram[i][0]))
			{
				
				if((num=is_equal(square[j],anagram[i][0],anagram[i][1]))!=0)
				{
					printf("%d->",square[j]);
					printf("%d\n",num);
					if(square[j]>max_num)
					{
						if(max_num<square[j])max_num=square[j];
						if(max<num) max_num=num;
					}
				}
			}
			else break;	
		}
	}
	printf("\n le max est :%d",max_num);
}
