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


long best[6000][6000];


struct data{
long weight;
long totcap;

data(const data& d)
{
	this->weight=d.weight;
	this->totcap=d.totcap;
}

data(long w, long cap) : weight(w), totcap(cap)
{
}

};


bool compare(const data& a, const data& b)
{
	return a.totcap<b.totcap;
}

long min(long a, long b)
{
	return a<b?a:b;
}
int main()
{
	vector<data> vec;
	long w, cap;
	memset(best,0,sizeof(best));
	while(cin>>w>>cap)
	{
		vec.push_back(data(w,cap));
	}
	sort(vec.begin(),vec.end(),compare);
	int max=1;
	for(int i=0;i<=vec.size();i++)
	{
		for(int j=0;j<=vec.size();j++)
		{
			if(i==0&&j!=0)
				best[i][j]=1000000047;
			else if(j==0)
				best[i][j]=0;
			else
			{
				if(best[i-1][j-1]+vec[i-1].weight<=vec[i-1].totcap)
				{
					best[i][j]=min(best[i-1][j-1]+vec[i-1].weight,best[i-1][j]);
					if(j>max)
					{
						max=j;
					}
				}
				else
				{
					best[i][j]=best[i-1][j];
				}
			}
		}
	}
	
	/*for(int i=0;i<=vec.size();i++)
 * 	{
 * 			for(int j=0;j<=11;j++)
 * 					{
 * 								cout<<best[i][j]<<" ";
 * 										}
 * 												cout<<endl;
 * 													}*/
	
	/*for(int k=0;k<vec.size();k++)
 * 	{
 * 			cout<<vec[k].weight<<" "<<vec[k ].totcap<<endl;
 * 				}*/
	cout<<max<<endl;
	return 0;
}
