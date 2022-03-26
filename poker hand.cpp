#include<stdio.h>
#include<ctype.h>
typedef struct
{
	char suit[5];
	int value[5];
}hand;
int num_card(char c)
{
	int answer=0;
	switch(c)
	{
		case'2':answer=2 ;break;
		case'3':answer=3 ;break;
		case'4':answer=4 ;break;
		case'5':answer=5 ;break;
		case'6':answer=6 ;break;
		case'7':answer=7 ;break;
		case'8':answer=8 ;break;
		case'9':answer=9 ;break;
		case'T':answer=10; break;
		case'J':answer=11 ;break;
		case'Q':answer=12 ;break;
		case'K':answer=13 ;break;
		case'A':answer=14 ;break;
		default: printf("ERROR");break;
	}
	return answer;	
}
int high_card(int* tab)
{
	int i,max=0;
	for(i=0;i<5;i++) if(max<tab[i]) max=tab[i];
	return max;	
}
int is_flush(char* tab)
{
	int i,answer=0;
	
	for(i=1;i<5;i++)
	{	
		 if(tab[0]!=tab[i])
		{
			answer++;
			break;
		}
	}
	if(answer==0)answer=1;
	else answer=0;
	
	return answer;	
}
int is_straight(int*tab)
{
	int i,j,min=0,answer=0;
	int num[5];
	for(i=0;i<5;i++) num[i]=tab[i];
	
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(num[j]<num[i])
			{
				min=num[j];
				num[j]=num[i];
				num[i]=min;
			}
		}
		if(i>0)
		{
			if(num[i]==num[i-1]+1) answer=1;
			else
			{
				answer=0;
				break;	
			}
		}
	}
	return answer;
}

int is_one_pair(int*tab)
{
	int answer=0,i,j;
	for(i=0;i<5;i++)
	{

		for(j=i+1;j<5;j++)
		{
			if(tab[i]==tab[j]) 
			{
				answer=tab[i];
				break;
			}
		}
		if(answer!=0)break;
	}
	return answer;
}

int is_two_pair(int*tab)
{
	int answer=0,i,j,test;
	
	if((test=is_one_pair(tab))!=0)
	{	
		for(i=0;i<5;i++)
		{
			if(tab[i]==test) continue;
			for(j=i+1;j<5;j++)
			{
				if(tab[i]==tab[j]) 
				{
					answer=1;
					break;
				}
			}
			if(answer!=0)break;
		}
			
	}
	return answer;
}
int n_of_kind(int*tab,int n)
{
	int i,j,answer;
	for(i=0;i<5;i++)
	{
		answer=1;
		for(j=i+1;j<5;j++)
		{
			if(tab[i]==tab[j]) answer++;
			if(answer==n) break;	
		}
		if(answer==n) break;
	}
	if(answer==n) answer=tab[i];
	else answer=0;
	
	return answer;
}

int is_full_house(int *tab)
{
	int answer=0;
	answer=n_of_kind(tab,3);
	if(answer&&is_two_pair(tab)) return answer;
	else return 0;

}
int straight_flush(int *num,char*tab)
{
	int answer=0;
 	if(is_flush(tab)&&is_straight(num)) 	answer=1;
 	return answer;
}
int royal_flush(int* num,char*tab)
{
	if(is_straight(num)&&is_flush(tab)&&high_card(num)==14)
	{
		return 1;
	}
	else return 0;	
}
main()
{
	
	FILE* file;
	file=fopen("poker.txt","r");
	
	int score1=0,score2=0,i=0,j=0;
	char c;
	hand player1[1000],player2[1000];
//copy the information to the arrays :player1 and player2 	
	while((c=fgetc(file))!=EOF)
	{
		
		if(c==' ') continue;
		else if(c=='\n')
		{
			j++;
			i=0;
		}
		else
		{		
			if(i<5)
			{	
				player1[j].value[i]=num_card(c);
				c=fgetc(file);
				player1[j].suit[i]=c;
			}
			else if(i>=5&&i<10)
			{	
				player2[j].value[i-5]=num_card(c);
				c=fgetc(file);
				player2[j].suit[i-5]=c;
			}			
			i++;
		}	
	}
	int m1,m2;
	//compare thee hand of player 1 and player2
	for(i=0;i<1000;i++)
	{
		m1=royal_flush(player1[i].value,player1[i].suit);
		m2=royal_flush(player2[i].value,player2[i].suit);
		if(m1==m2)
		{
			m1=straight_flush(player1[i].value,player1[i].suit);
			m2=straight_flush(player2[i].value,player2[i].suit);
			if(m1==m2)
			{
				m1=n_of_kind(player1[i].value,4);
				m2=n_of_kind(player2[i].value,4);
				if(m1==m2)
				{
					m1=is_full_house(player1[i].value);
					m2=is_full_house(player2[i].value);
					if(m1==m2)
					{
						m1=is_flush(player1[i].suit);
						m2=is_flush(player2[i].suit);
						if(m1==m2)
						{
							m1=is_straight(player1[i].value);
							m2=is_straight(player2[i].value);
							if(m1==m2)
							{
								m1=n_of_kind(player1[i].value,3);
								m2=n_of_kind(player2[i].value,3);
								if(m1==m2)
								{
									m1=is_two_pair(player1[i].value);
									m2=is_two_pair(player2[i].value);
									if(m1==m2)
									{
										m1=is_one_pair(player1[i].value);
										m2=is_one_pair(player2[i].value);
										if(m1==m2)
										{
											m1=high_card(player1[i].value);
											m2=high_card(player2[i].value);
											if(m1>m2) score1++;
											else score2++;
										}
										else if(m1>m2) score1++;
										else score2++;
									}
									else if(m1>m2) score1++;
									else score2++;
								}
								else if(m1>m2) score1++;
								else score2++;
							}
							else if(m1>m2) score1++;
							else score2++;
						}
						else if(m1>m2) score1++;
						else score2++;
					}
					else if(m1>m2) score1++;
					else score2++;
				}
				else if(m1>m2) score1++;
				else score2++;	
			}
			else if(m1>m2) score1++;
			else score2++;
		}
		else if(m1>m2) score1++;
		else score2++;	
	}
	//answer
	printf("player1=%d\nplayer2=%d\n",score1,score2);	
}
