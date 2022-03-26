#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int is_1_HCF(int n,int d)
{
	int i,answer=1;
	if(d<n) answer=0;
	else 
	for(i=2;i<=n;i++)
	{
		if(n%i==0&&d%i==0)
		{
			answer=0;
			break;
		}
	}
	return answer;
}
main()
{
	int d;
	for(d=142857;d>=2;d--)
	{
		if(is_1_HCF(3*d-1,7*d))
		{
			printf("%d/%d\nanswer is %d",3*d-1,7*d,3*d-1);
			exit(1);
		}	
	}
}
