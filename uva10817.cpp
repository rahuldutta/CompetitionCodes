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
//Taken hint
using namespace std;

long long costDP[(1<<8)][(1<<8)][101];
long long personCost[101];
long long personMask[101];
int S,N;

long long DP(long long b1, long long b2, int i)	
{
	if(b1==((1<<S)-1)&&b2==((1<<S)-1))
	{
		return 0;
	}
	else if(i>=N)
	{
		return 5000000;
	}
	else if(costDP[b1][b2][i]!=-1)
	{
		return costDP[b1][b2][i];
	}
	else
	{
		costDP[b1][b2][i]= min<long long>(DP(b1,b2,i+1),(personCost[i]+DP(b1|personMask[i],b2|(b1 & personMask[i]),i+1)));
		return costDP[b1][b2][i];
	}
}

int main()
{
	while(1)
	{
		string s;
		getline(cin,s);
		stringstream iss;
		iss.clear();
		iss.str("");
		iss << s;
		int M;
		iss>>S>>M>>N;
		if(S==0)
			break;
		int i,j,k;
		long long cost=0;
		long long b1=0,b2=0;
		for(i=0;i<M;i++)
		{
			getline(cin,s);
			iss.clear();
			iss.str("");
			iss << s;
			long long c;
			iss>>c;
			cost+=c;
			while(!iss.eof())
			{
				if(isspace(iss.peek()))
					iss >> ws;
				else
				{
					long long m;
					iss>>m;
					b2 |=(b1&(1<<(m-1)));
					b1 |= (1<<(m-1));
				}
			}
		}
		//cout<<b1<<" "<<b2<<endl;
		//cout<<cost<<endl;
		memset(personMask,0,sizeof(personMask));
		memset(costDP,-1,sizeof(costDP));
		for(i=0;i<N;i++)
		{
			getline(cin,s);
			iss.clear();
			iss.str("");
			iss << s;
			long long c;
			iss>>c;
			personCost[i]=c;
			while(!iss.eof())
			{
				if(isspace(iss.peek()))
					iss >> ws;
				else
				{
					long long m;
					iss>>m;
					personMask[i] |= (1<<(m-1));
				}
			}
			//cout<<personCost[i]<<" "<<personMask[i]<<endl;
		}
		cout<<(cost+DP(b1,b2,0))<<endl;
	}
	return 0;
}
