#include<stdio.h>
int days;
// 0 --> On time
// 1 --> Absent
// 2 --> Late
long long  solve(int day,int L,int A)
{
	long long answer=0;
	if(day==days)
	{
		answer++;
		return answer;
	}
	
	//On time
	//A=0 because the consuctive of A is breaken
	answer+=solve(day+1,L,0);
	 
	//Absent
	//to not have late==3
	//another caracter 'A' consuctive 
	if(A<2)	answer+=solve(day+1,L,A+1);
	
	//Late
	//to not have late>1
	//A=0 because the consuctive of A is breaken 
	if(L<1)	answer+=solve(day+1,L+1,0);
	
	return answer;//final answer 
}
main()
{
	days=30;
	printf("--->%d",solve(0,0,0));
	
}
