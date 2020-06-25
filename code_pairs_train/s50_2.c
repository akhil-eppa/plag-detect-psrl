/*
// Sample code to perform I/O:
#include <stdio.h>
 
int main(){
	int num;
	scanf("%d", &num);              			// Reading input from STDIN
	printf("Input number is %d.\n", num);       // Writing output to STDOUT
}
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#define MAX_RANKING_ELEMENTS 500005
#define MAX_QUERIES 100000
 
long long iRankArray[MAX_RANKING_ELEMENTS];
 
long long  iDoBinarySearchToInsert(int iStart,int iEnd,int iBugValue)
{
	long long iMid = iStart+(iEnd - iStart)/2;
 
	if(iEnd<=iStart)
		return (iBugValue > iRankArray[iStart])? iStart+1: iStart;
 
	if(iBugValue == iRankArray[iMid])
	{
		return iMid+1;
	}
	else if(iBugValue > iRankArray[iMid])
	{
		iStart =  iMid+1;
		return iDoBinarySearchToInsert(iStart,iEnd,iBugValue);
	}
	else if(iBugValue < iRankArray[iMid])
	{
		iEnd =  iMid;
		return iDoBinarySearchToInsert(iStart,iEnd,iBugValue);
	}
}
void iDoInsertionSort(int iSize,int iBugValue)
{
	long long iTemp = iSize-1;
	long long iLoc =  iDoBinarySearchToInsert(0,iTemp,iBugValue);
    
	while(iTemp>=iLoc)
	{
		iRankArray[iTemp+1] = iRankArray[iTemp];
		iTemp--;
	}
	iRankArray[iTemp+1] = iBugValue;
}
int main()
{
    long long iEleInArray =0,iNumEle =0,iNumQueries=0,iTask =0,iBugValue =0,iQuery=0, iArrayStart =0;
    
    scanf("%lld", &iNumEle);
 
    for(long long i=0; i<iNumEle; i++)
	{	
	scanf("%lld", &iTask);
 
		if(iTask ==1)
		{
			scanf("%lld", &iBugValue);
			if(iEleInArray == 0)
			{
				iRankArray[iEleInArray++] = iBugValue;
			}
			else
			{
				iDoInsertionSort(iEleInArray,iBugValue);
				iEleInArray++;
			}
		}
		else if(iTask == 2 )
		{
			if( iEleInArray < 3) printf("Not enough enemies\n");
			else 
			{
				long long iNdx = iEleInArray/3;
				 printf("%lld\n",iRankArray[iEleInArray-iNdx]);
			}
		}
		
    }
    return 0;
}