#include<stdio.h>
int currentRow[1000]={0};
int lastRow[1000]={0};
void processRow(int count )
{
	int idx,left,right;
	for(idx=0;idx<=count;idx++)
	{
		if(idx==0)
		{
			currentRow[idx]+=lastRow[idx];	
			
		}
		else if(idx==count)
		{
			currentRow[idx]+=lastRow[idx-1];
			
		}
		else
		{
			left=currentRow[idx]+lastRow[idx-1];
			right=currentRow[idx]+lastRow[idx];
			currentRow[idx]=(left>right)? left:right;
			
			
		}
	}
	for(idx=0;idx<=count;idx++)
	{
		lastRow[idx]=currentRow[idx];
	}
}
main()
{
	int temp=0;
	int rowIdx=0;
	
	char c;
	int i;
	FILE *file;
		
	
	file=fopen("triangle.txt","r");
    
    
    while((c=fgetc(file))!=EOF)
    {
    	if(c=='\n')
    	{
    		currentRow[rowIdx]=temp;
    		temp=0;
    		processRow(rowIdx);
    		rowIdx=0;
		}
		else if(c==' ')
		{
			currentRow[rowIdx]=temp;
			temp=0;
			rowIdx++;	
		}
		else
		{
			temp*=10;
			temp+=(c-'0');
		}
	}
	currentRow[rowIdx]=temp;
	processRow(rowIdx);
	int max=0;

for(i=0;i<=rowIdx;i++)
{
	if(max<lastRow[i])max=lastRow[i];
}

printf("\nmax=%d",max);
fclose(file);

}
