#include<stdio.h>
int num_days_in_year(int year)
{	
	int shine=0,leap=0;		
	if(year%4!=0||(year%400!=0&&year%100==0))  shine++;	
	
	else if(year%4==0) leap++;
		
int days=365*shine+366*leap;
	return days;
}

int num_days_month(int month,int year)
{
	switch(month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		    return 31;
		    break;
	
	    case 4: case 6: case 9: case 11:
		    return 30;
		    break;
		
		case 2:
			if(num_days_in_year(year)==365) return 28;
			else return 29;
			break;
		default:
				printf("\nERROR,The information is incorrect!\n");
				return 0;
				break;
	}
}

int from_1900_to_day(int day,int month,int year)
//number of days beetween  1/1/1900 and a  selected date 
{
	int days=day-1;
	int i;
	for(i=1;i<month;i++)
	{
		days+=num_days_month(i,year);
	}
	if(year-1900!=0)
	for(i=year-1;i>=1900;i--)
	days+=num_days_in_year(i);	
	return days;	
}

int name_day(int day,int month,int year)
{
	int m=0;
	m=from_1900_to_day(day,month,year);
	
	while(m>6) m-=7;
	return m;	
}

int first_day_months(int find,int year)
{
	int i,j,k=0;
	for(i=1901;i<=year;i++)
	{
		for(j=1;j<=12;j++)
		{
			if(name_day(1,j,i)==find)
			{
			k++;
			printf("1/%d/%d---> %d\n",j,i,name_day(1,j,i));
			 } 
		}
		printf("\n");
	}
	return k;	
}
main()
{	
int k=0;
int i;
printf("\tenter a number of the day");
 printf("\nmonday enter :    0\n"); 
		printf("tuesday enter:   1\n"); 
		printf("wednesday enter: 2\n");
		printf("thirsday enter:  3\n");
		printf("friday enter :   4\n");
		printf("saturday enter:  5\n");
		printf("sunday enter :   6\n");	
scanf("%d",&i);	
k=first_day_months(i,2000);
printf("the day %d fell in the first month for %d",i,k);
	
}
