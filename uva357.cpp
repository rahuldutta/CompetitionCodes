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
long int ways[30001][6]={{0}};
int cents[5]={1,5,10,25,50};


void calculate()
{
	int i,j,k;
	for(i =0;i<30001;i++)
	{
		ways[i][0]=0;
	}
	for(i =0;i<6;i++)
	{
		ways[0][i]=1;
	}
	for(i=1;i<30001;i++)
	{
		for(j=1;j<6;j++)
		{
			if((i-cents[j-1])>=0)
			{
				ways[i][j]=ways[i][j-1]+ways[i-cents[j-1]][j];
			}
			else
			{
				ways[i][j]=ways[i][j-1];
			}
		}
	}
}

int main()
{
	calculate();
	int N;
	while(cin>>N)
	{
		long int k=ways[N][5];
		if(k==1)
		{
			cout<<"There is only "<<k<<" way to produce "<<N<<" cents change."<<endl;
		}
		else
		{
			cout<<"There are "<<k<<" ways to produce "<<N<<" cents change."<<endl;
		}
	}
}
