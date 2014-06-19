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
#include<climits>

# define max_int 9999


using namespace std;

struct schedule
{
	int day;
	vector<int> cost;
	schedule(const schedule& sc)
	{
		day=sc.day;
		cost=sc.cost;
	}
	schedule(int d, vector<int> c)
	{
		day=d;
		cost=c;
	}
	schedule()
	{
		day=0;
	}
	void show()
	{
		cout<<day<<" ";
		for(int i=0;i<cost.size();i++)
		{
			cout<<cost[i]<<" ";
		}
		cout<<endl;
	}
};


int retPrice(int i, int j, int k, schedule arr[10][10])
{
	schedule s=arr[i-1][j-1];
//	s.show();
	int c= s.cost[(k-1)%s.day];
//	cout<<c;
	if(c==0)
		return INT_MAX;
	return c;
}

int main()
{
	int N,K;
	int counter=1;
	while(cin>>N>>K)
	{
		int i,j,k;
		schedule arr[10][10];
		int dp[11][1001]={{0}};
		if(N==0&&K==0)
			return 0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(j==i)
					continue;
				int d;
				cin>>d;
				vector<int> c(d);
				for(k=0;k<d;k++)
				{
					cin>>c[k];
				}
				schedule sc(d,c);
				arr[i][j]=sc;
			}
		}
		/*
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(j==i)
					continue;
				arr[i][j].show();
			}
		}*/
		
		dp[1][1]=INT_MAX;
		for(i=2;i<=N;i++)
		{
			dp[i][1]=retPrice(1,i,1,arr);
			//cout<<dp[i][1];
			//int temp;
			//cin>>temp;
		}
		for(j=2;j<=K;j++)
		{
			for(i=1;i<=N;i++)
			{
				int min=INT_MAX;
				for(k=1;k<=N;k++)
				{
					if(k==i)
						continue;
					int temp=retPrice(k,i,j,arr);
					if(temp==INT_MAX||dp[k][j-1]==INT_MAX)
						continue;
					int c=dp[k][j-1]+temp;
					
					if(c<min)
						min=c;
				}
				dp[i][j]=min;
			}
		}
		/*
		for(i=1;i<=N;i++)
		{
			for(j=1;j<=K;j++)	
			{
				printf("%5d",dp[i][j]);
			}
			cout<<endl;
		}*/
		cout<<"Scenario #"<<counter<<endl;
		if(dp[N][K]>=INT_MAX)
		{
			cout<<"No flight possible.\n";
		}
		else
		{
			cout<<"The best flight costs "<<dp[N][K]<<".\n";
		}
		cout<<endl;
		counter++;
		
	}
	return 0;
}
