#include<stdio.h>
#include<math.h>
#define int_64bit unsigned long long 
int_64bit digit_sum(int_64bit num)
{
	int_64bit answer=0;
	while(num!=0)
	{
		answer+=num%10;
		num/=10;
	}
	return answer;
}
is_equal(int_64bit num)
{
	int_64bit sum=digit_sum(num);
	
	int_64bit answer=0;
	if(sum!=1)
	while(num%sum==0)
	{
		num/=sum;;	
	}
	
	if(num==1&&sum!=1) return 1;
	else return 0;
	
	return answer;	
}
main()
{
	int_64bit i,l=0,j;
	int_64bit tab[10000];
	for(i=1;i<64;i++)// i choose 64 because it's the limit (2^63)
	{
		for(j=2;j<800;j++)
		{
			
			if(ceil(i*log(j)/log(10))>17) break;//the biggest number  in C :  integer 2^63
			else if(ceil(i*log(j)/log(10))==1&&j!=10) continue;//to the numbers below 10 
			int_64bit num=pow(j,i);
			if(is_equal(num))
			{
				tab[l]=num;
				l++;
			}
		}
	}
	//delete the repetition 
	// orgnazing the value from the lowest to the the bigger
	for(i=0;i<l;i++)
	{
		if(tab[i]==0)continue;
		for(j=i+1;j<l;j++)
		{
			if(tab[j]==0)continue;
			else if(tab[i]==tab[j])
			{
				
				tab[j]=tab[l-1];
				tab[l-1]=0;
				l--;
				
			}
			else if(tab[i]>tab[j])
			{
				int_64bit num=tab[j];
				tab[j]=tab[i];
				tab[i]=num;
			}
		}
	}
	
	printf("--->%lld",tab[30-1]);
}
