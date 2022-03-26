#include<stdio.h>
#include<math.h>
int num_digit(int a)
//calculate number of digits of the a
{
	int i=1;
	for(i=1;a>=pow(10,i);i++) continue;
	return i;
}
main()
{
	int i,j=0,k=0,test=0,num;	
	int max=1;		
for(i=1;;i++)//numbers 
{
	j+=num_digit(i);
	if(j>1000000) break; // the max
	
	if(j>=pow(10,k))
	// d1,d10,d100...d1000000
	{	
		num=i/pow(10,j-pow(10,k));
		test=num/10;
		num-=test*10;
		max*=num;	
		k++;	
	}			
}
	printf("max=%d",max);	
}
