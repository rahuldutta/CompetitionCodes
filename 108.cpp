using namespace std;
#include<iostream>
#include<stdio.h>
#define Inf 1ll<<60



/*void KadaneAlgo(int arr[])
{
    //(maxSum, maxStartIndex, maxEndIndex) := (-INFINITY, 0, 0)
    long long currentMaxSum = 0;
    long long currentStartIndex =0;
    long long currentEndIndex=0;
    for (currentEndIndex = 1; currentEndIndex<n;currentEndIndex++)
    {
        currentMaxSum = currentMaxSum + arr[currentEndIndex];
        if (currentMaxSum > maxSum)
            {
			maxSum=currentMaxSum;
			maxStartIndex=currentStartIndex;
			maxEndIndex= currentEndIndex;
        }
        if (currentMaxSum < 0 )
        {
            currentMaxSum = 0;
            currentStartIndex = currentEndIndex + 1;
			}
        
    }
   
}
*/
int main()
{
 	long long N,i,j,k;
 	
 	while(cin>>N)
 	{
	 			 long long maxSum=-Inf;
long long maxStartIndex=0;
 long long maxEndIndex=0;
 long long maxStarty=0;
 long long maxEndy=0;
	 			long long mat[N][N];
				  for(i=0;i<N;i++)
				  {
				   				  for(j=0;j<N;j++)
				   				  {
								   				  cin>>k;
								   				  if(i==0)
								   				  mat[i][j]=k;
								   				  else
								   				  mat[i][j]=k+mat[i-1][j];
								   }
				   }
				for(i=0;i<N;i++)
				{
				 				for(j=i;j<N;j++)
								 {
						long long currentMaxSum = 0;
    long long currentStartIndex =0;
    long long currentEndIndex=0;
    for (; currentEndIndex<N;currentEndIndex++)
    {
	 	if(i==0)
        currentMaxSum = currentMaxSum + mat[j][currentEndIndex];
        else
        currentMaxSum = currentMaxSum + mat[j][currentEndIndex]-mat[i-1][currentEndIndex];
        if (currentMaxSum > maxSum)
            {
			maxSum=currentMaxSum;
			maxStartIndex=currentStartIndex;
			maxEndIndex= currentEndIndex;
			maxStarty=i;
			maxEndy=j;
        }
        if (currentMaxSum < 0 )
        {
            currentMaxSum = 0;
            currentStartIndex = currentEndIndex + 1;
			}		  												  
}
}
}
cout<<maxSum<<"\n";
/*for(i=maxStarty;i<maxEndy;i++)
{
 							  for(j=maxStartIndex;j<maxEndIndex;j++)
 							  {
							   										cout<<mat[i][j];
																	}
																	}*/
																	}
																	return 0;
																	}
