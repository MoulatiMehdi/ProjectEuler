#include<stdio.h>
#include<conio.h>
const int size=2;
const int start=2;
const int limit=10;
int tab[size+start]={0};

long long solve(int k)
{
	long long answer=0;
	if(k==size)
	{
		for(int i=start;i<start+k;i++)
		{
			printf("%d",tab[i]);
		}
		printf("\n");
		answer++;
		return answer;
	}
	
	for(int i=0;i<limit-tab[k+start-1]-tab[k+start-2];i++)
	{
		if(k==0&&i==0) continue;
		tab[k+start]=i;
		answer+=solve(k+1);
	}
	
	return answer;
}
main()
{
	printf("\n--->%lld",solve(0));
}

