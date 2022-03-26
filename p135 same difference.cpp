#include<stdio.h>
#include<stdlib.h>
#define limit 50000000
#define n 1
int *solution=(int*)calloc(limit+1,sizeof(int));
void solve(int max)
{
	int i,j;
	for(i=1;i<=max;i++)
	{
		for(j=1;j*i<=max;j++)
		{
			if((i+j)%4!=0||(3*j-i)%4!=0||3*j<=i)continue;
			solution[i*j]++;
		}
	}
}
main()
{
	solve(limit);
	int answer=0;
	for(int i=0;i<=limit;i++)
	{
		if(solution[i]==n)answer++;
	}
	printf("--->%d",answer);
}
