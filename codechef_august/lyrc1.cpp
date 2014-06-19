#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#include<cstdlib>
 
using namespace std; 
char Pat[500][5000];
int LPS[500][5000];
char A[50000];
long long Ans[500];


void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(int size)
{ 
    int N = strlen(A);
    
    for(int k=0;k<size;k++)
    {
		int M = strlen(Pat[k]);
		// create lps[] that will hold the longest prefix suffix values for pattern
		int j  = 0;  // index for pat[]
	 
		// Preprocess the pattern (calculate lps[] array)
	   
		int i = 0;  // index for txt[]
		while(i < N)
		{
		  if(Pat[k][j] == A[i])
		  {
		    j++;
		    i++;
		  }
	 
		  if (j == M)
		  {
		    //printf("Found pattern at index %d \n", i-j);
		    Ans[k]+=1;
		    j = LPS[k][j-1];
		  }
	 
		  // mismatch after j matches
		  else if(Pat[k][j] != A[i])
		  {
		    // Do not match lps[0..lps[j-1]] characters,
		    // they will match anyway
		    if(j != 0)
		     j = LPS[k][j-1];
		    else
		     i = i+1;
		  }
		}
	}

}
 
void computeLPSArray(int index )
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    LPS[index][0] = 0; // lps[0] is always 0
    i = 1;
 	int M=strlen(Pat[index]);
    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M)
    {
       if(Pat[index][i] == Pat[index][len])
       {
         len++;
         LPS[index][i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if( len != 0 )
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = LPS[index][len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           LPS[index][i] = 0;
           i++;
         }
       }
    }
}

int main()
{
	
   //cout<<KMPSearch(pat, txt)<<endl;
	int W;
	scanf("%d",&W);
	int i,j;
	for(i=0;i<W;i++)
	{
		scanf("%s",Pat[i]);
		computeLPSArray(i);
	}
	int N;
	scanf("%d",&N);
	memset(Ans,0,sizeof(Ans));
	for(j=0;j<N;j++)
	{
		scanf("%s",A);
		KMPSearch(W);
	}
	for(i=0;i<W;i++)
	{
		printf("%lld\n",Ans[i]);
	}
	return 0;
}
