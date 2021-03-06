#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>

using namespace std;

int value[31][1001];
int taken[31];

int max1(int a,int b)
{
	return a>b?a:b;
}

int knapsack(int val[], int wt[], int totwt, int n, int weight)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=totwt;j++)
		{
			if(i==0||j==0)
				value[i][j]==0;
			else
			{
				if(j-wt[i-1]>=0)
				{
					value[i][j]=max1(value[i-1][j],(val[i-1]+value[i-1][j-wt[i-1]]));
				}
				else
				{
					value[i][j]=value[i-1][j];
				}
			}
		}
	}
	int notreasure=0;
	for(int w=totwt,s=n;s>0;s--)
	{
		if(value[s][w]==value[s-1][w])
		{
			taken[s-1]=0;
		}
		else
		{
			taken[s-1]=1;
			w=w-wt[s-1];
			notreasure++;
		}
	}
	
	cout<<value[n][totwt]<<endl;
	cout<<notreasure<<endl;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		//cout<<taken[i];
		if(taken[i]==1)
		{	
			/*if(flag==1)
				cout<<endl;
			else	
				flag=1;*/
			cout<<wt[i]/(3*weight)<<" "<<val[i]<<endl;
		}
	}
}

int main()
{
	int t,w;
	int flag=0;
	while(cin>>t>>w)
	{
		if(flag==1)
			cout<<endl;
		else
			flag=1;
		int wt[31], val[31];
		int no;
		cin>>no;
		for(int i=0;i<no;i++)
		{
			int ti, pr;
			cin>>ti>>pr;
			val[i]=pr;
			wt[i]=3*w*ti;
		}
		knapsack(val,wt,t,no,w);
	}
	return 0;
}
