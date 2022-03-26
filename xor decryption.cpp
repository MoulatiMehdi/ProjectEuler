#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
main()
{
	int i,j,k,num,max=1;
	FILE* file;
	
	char c;
	
	file=fopen("cipher.txt","r");
	//number of encryption caracter in file	
	while((c=fgetc(file))!=EOF)
	{	
		if(c==',')	max++;
	}
	fclose(file);
	//convert the encryption caracter to ASCII number
	file=fopen("cipher.txt","r");
	int encryption[max]={0};
	for(i=0;i<max;i++)
	{
		while((c=fgetc(file))!=EOF&&c!=',')
		{
			encryption[i]*=10;
			encryption[i]+=c-'0';
		}
	}
	//find the key
	int key[3];
	int num_key,test,l;
	for(i=0;;i++)
	{
		test=0;
		for(k='a';k<='z';k++)
		{
			num=encryption[i]^k;
			if(num==' ')
			{
				j=i;
				while(j>=3) j-=3;	
				for(l=0;l<num_key;l++) if(key[l]==k) test++;
			
				if(test==0)
				{
				key[j]=k;
				num_key++;
				}		
			} 
			if(num_key==3) break;
		}
		if(num_key==3) break;
	}
	int sum=0;
	for(i=0,j=0;i<max;i++,j++)
	{
		encryption[i]^=key[j];
		printf("%c",encryption[i]);
		sum+=encryption[i];
		if(j==2) j=-1;
	}
	
	printf("\nsum=%d",sum);
	
}
