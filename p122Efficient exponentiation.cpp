#include<stdio.h>
#include<stdlib.h>
#define limit 200
int *cost=(int*)calloc(limit+1,sizeof(int));
int *path=(int*)calloc(limit+1,sizeof(int));

void Backtrack(int power, int depth) 
{
    if (power > limit || depth > cost[power]) return;
    cost[power] = depth;
    path[depth] = power;
    for (int i = depth; i >= 0; i--)
    Backtrack(power + path[i], depth + 1);
}
main()
{
	for(int i=0;i<=limit;i++)
	cost[i]=i;
	Backtrack(1,0);
	int result=0;
	for(int i=1;i<=limit;i++)
		result+=cost[i];
		
	printf("%d",result);
}
