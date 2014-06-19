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
int DP[31][1001];

int max1(int a, int b)
{
	return a>b?a:b;
}

int Knapsack(int val[], int Wt[],int W, int N)
{
	for(int j=0;j<=N;j++)
	{
		for(int i=0;i<=W;i++)
		{
			if(i==0||j==0)
				DP[i][j]==0;
			else
			{
				if(Wt[j-1]<=i)
				{
					DP[i][j]=max1((val[j-1]+DP[i-Wt[j-1]][j-1]),DP[i][j-1]);
				}
				else
				{
					DP[i][j]=DP[i][j-1];
				}
			}
		}
	}
	/*
	for(int j=0;j<=W;j++)
	{
		for(int i=0;i<=N;i++)
		{
			cout<<DP[j][i]<<" ";
		}
		cout<<endl;
	}
	
	cout<<DP[W][N];
	*/
}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		memset(DP,0,sizeof(DP));
		int N;
		cin>>N;
		int Wt[1000]={0};
		int val[1000]={0};
		for(int i=0;i<N;i++)
		{
			cin>>val[i]>>Wt[i];
			//cout<<val[i]<<" "<<Wt[i]<<endl;
		}
		int G;
		cin>>G;
		int capacity[100];
		int max=0;
		for(int j=0;j<G;j++)
		{
			cin>>capacity[j];
			if(capacity[j]>max)
			max=capacity[j];
		}
		//cout<<"max "<<max<<endl;
		Knapsack(val,Wt,max,N);
		//cout<<DP[max][N];
		int sum=0;
		for(int j=0;j<G;j++)
		{
			sum+=DP[capacity[j]][N];
		}
		cout<<sum<<endl;
		
		
	}
}
