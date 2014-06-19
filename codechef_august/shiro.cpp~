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

using namespace std;
double arr[101][10001];
int vis[101][10001];
int a[100];
double p[100];

double DP(int i,int totflags, int halfflags, int N)
{
	//cout<<i<<" "<<totflags<<" "<<arr[i][totflags]<<" "<<vis[i][totflags]<<endl;
	//cin.get();
	if(totflags<halfflags)
		return 0;
	if(i==N)
		return 1;
	if(vis[i][totflags])
		return arr[i][totflags];
	arr[i][totflags]=p[i]*(DP(i+1,totflags,halfflags,N))+(1-p[i])*(DP(i+1,totflags-a[i],halfflags,N));
	//cout<<arr[i][totflags]<<endl;
	vis[i][totflags]=1;
	return arr[i][totflags];
}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int N,i,j;
		cin>>N;
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(arr,0,sizeof(arr));
		memset(vis,0,sizeof(vis));
		double totflags=0;
		for(i=0;i<N;i++)
		{
			cin>>a[i];
			totflags+=a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>p[i];
			p[i]/=100;
		}
		int halfflags=ceil(totflags/2);
		//cout<<totflags<<" "<<halfflags<<endl;
		//cin.get();
		//cout<<DP(0,totflags,halfflags,N)<<endl;
		printf("%.9lf\n",DP(0,totflags,halfflags,N));
	}
	return 0;
}
