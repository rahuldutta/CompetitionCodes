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
#include <limits.h>

using namespace std;
int arr[26]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
int memDP[27][360][26];


int DP(int n, int S, int i)
{
	if(n==0&&S==0)
	{
		return 1;
	}
	else if(n==0||S==0||i<0)
	{
		return 0;
	}
	else if(memDP[n][S][i]!=-1)
	{
		return memDP[n][S][i];
	}
	else
	{
		memDP[n][S][i]=DP(n,S,i-1)+DP(n-1,S-arr[i],i-1);
		return memDP[n][S][i];
		//return DP(n,S,i-1)+DP(n-1,S-arr[i],i-1);
	}
}

int main()
{
	
	int n,S,cases=1;
	memset(memDP,-1,sizeof(memDP));
	while(1)
	{
			
		cin>>n>>S;
		if(n==0&&S==0)
			break;
		cout<<"Case "<<cases<<": ";
		if(n>26||S>351)
			cout<<0<<endl;
		else if(n==0||S==0)
			cout<<0<<endl;
		else
			cout<<DP(n,S,min<int>(25,S-1))<<endl;
		cases++;
	}
	return 0;
}
