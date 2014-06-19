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

struct block{
int x,y,h;
block(int x, int y, int z) : x(x), y(y), h(z)
{}

};

bool operator<(const block& a, const block& b)
{
	return a.x*a.y<b.x*b.y;
}

bool cmp(block& a, block& b)
{
	return a.x<b.x && a.y<b.y || a.x<b.y && a.y<b.x;
}

int main()
{
	int N;
	int counter=1;
	while(cin>>N)
	{
		if(N==0)
			return 0;
		/*
		if(counter>1)
			cout<<endl;
			*/
		int i,j;
		vector<block> cj;
		vector<int> dp(3*N);
		for(i=0;i<N;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			block b(x,y,z);
			cj.push_back(b);
			block b1(z,y,x);
			cj.push_back(b1);
			block b2(x,z,y);
			cj.push_back(b2);
		}
		
		sort(cj.begin(),cj.end());
		/*
		for(i=0;i<3*N;i++)
		{
			cout<<cj[i].x<<" "<<cj[i].y<<" "<<cj[i].h<<endl;
		}*/
		dp[0]=cj[0].h;
		int ov_max=dp[0];
		for(i=1;i<3*N;i++)
		{
			int max=cj[i].h;
			for(j=0;j<i;j++)
			{
				if(cmp(cj[j],cj[i]))
				{
					if((dp[j]+cj[i].h)>max)
					{
						max=dp[j]+cj[i].h;
					}
				}
			}
			dp[i]=max;
			if(ov_max<dp[i])
			{
				ov_max=dp[i];
			}
		}
		/*
		for(i=0;i<3*N;i++)
		{
			cout<<dp[i]<<endl;
		}*/
		cout<<"Case "<<counter<<": maximum height = "<<ov_max<<endl;
		counter++;
	}
	return 0;
}
