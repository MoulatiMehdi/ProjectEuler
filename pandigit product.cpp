#include<stdio.h>
#include<conio.h>
#include<math.h>
int num_digit(int a)
{
	int i;
	for(i=0;;i++)
	{
		if(a==0)
		{
			i=1;
			break;
		} 
		else if(pow(10,i)>a) break;
	}
	
	return i;
}
void div_num(int a,int *sum)
{
	int k,j,i,t1,t2;
	int n_d1,n_d2,n_da;
	int num,test1[4],test2[4],testa[4];
		
		n_da=num_digit(a);
		for(j=2;j<sqrt(a);j++)
		{
			num=a;
			
				for(i=0;i<n_da;i++)
				//testing the number j
				{
					testa[i]=num/pow(10,n_da-1-i);
					num-=testa[i]*pow(10,n_da-1-i);		
				}			
			if(a%j==0) 
			{	
				num=j;
				t1=0;
				
				n_d1=num_digit(j);
				n_d2=num_digit(a/j);
				
				for(i=0;i<n_d1;i++)
				//testing the number j
				{
					test1[i]=num/pow(10,n_d1-1-i);
					num-=test1[i]*pow(10,n_d1-1-i);
					//testing if the digits are diffrent or not
					for(k=0;k<i;k++)
					{
						if(test1[i]==test1[k]||test1[i]==0)
						{	
							t1++;	
							break;	
						}		
					}
					if(t1!=0) break;
				}			
				num=a/j;
				t2=0;
				for(i=0;i<n_d2;i++)
				//testing the number a/j
				{
					test2[i]=num/pow(10,n_d2-1-i);
					num-=test2[i]*pow(10,n_d2-1-i);
					//testing if the digits are diffrent or not
					for(k=0;k<i;k++)
					{
						if(test2[i]==test2[k]||test2[i]==0)
						{	
							t2++;
							break;	
						}		
					}
					if(t2!=0) break;					
				}
			int n;
			for(n=0;n<n_da;n++)
				{
			//testing j and a/j with a
				for(i=0;i<n_d1;i++)
				//testing the number j and a/j
				{
					for(k=0;k<n_d2;k++)
						{
						if(test1[i]==test2[k]||test1[i]==testa[n]||test2[k]==testa[n])
							{
								
								t2++;
								break;
							}
							if(t2!=0) break;
						}
					if(t2!=0) break;	
					}
				}		
			if(t2==0&&t1==0&&n_d1+n_d2+n_da==9)
				{
					
					*sum+=a;
					printf("%d*%d=%d------->%d\n",j,a/j,a,*sum);
					break;
				}	
			}
		}
}

main()
{
	int i,j,k=0,result=0;
	int num=0,test,sum=0;
	int tab[4]={0};//testing
	int prod[3024]={0};//product numbers
	for(i=1000;i<10000;i++)
	{
		num=i;
		test=0;
		//divide a number to digits
		for(j=0;j<4;j++)
		{
			tab[j]=num/pow(10,3-j);
			num-=tab[j]*pow(10,3-j);
		//testing if the digits are diffrent or not
			for(k=0;k<j;k++)
			{
			if(tab[j]==tab[k]||tab[j]==0)
				{	
					test++;
					break;	
				}		
			}
			if(test!=0) break;		
		}
		if(test==0)
		{
			prod[result]=i;	
			result++;		
		}	
	}
	
	for(i=0;i<result;i++) div_num(prod[i],&sum);	
        printf("\nthe sum is :%d",sum);	
}
