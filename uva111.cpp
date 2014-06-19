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
#define N 20
using namespace std;
int DP[N+1][N+1];
int arr[N];
int comp[N];



int main()
{

	int T;
	cin>>T;
	
		 
	for(int i=0;i<T;i++)
	{
		int temp;
		cin>>temp;
		arr[temp-1]=i+1;
		
	}
	int t;
	while(cin>>t)
	{
		comp[t-1]=1;
		int j;
		for(j=1;j<T;j++)
		{
			int temp;
			cin>>temp;
			comp[temp-1]=j+1;
			DP[j][0]=0;
			DP[0][j]=0;
		}
		for(j=1;j<=T;j++)
		{
			for(int k=1;k<=T;k++)
			{
				if(arr[j-1]==comp[k-1])
				{
					DP[j][k]=DP[j-1][k-1]+1;
				}
				else if(DP[j-1][k]>DP[j][k-1])
				{
					DP[j][k]=DP[j-1][k];
				}
				else
				{
					DP[j][k]=DP[j][k-1];
				}
			}
		}
		cout<<DP[T][T]<<endl;
	}
	
}
