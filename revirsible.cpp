#include<stdio.h>
#include<math.h>
int c(int n)
{
	int answer=1,i;
	i=(n+1)/float(4);
	answer*=100;
	answer*=pow(500,i)-1;
	answer/=499;
	
	i=n/2;
	
	answer+=20*(pow(30,i)-1)/float(29);
	
	return answer;
}
main()
{
	printf("%d",c(9));
}
