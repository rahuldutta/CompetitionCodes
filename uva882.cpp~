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
# took help from http://apps.topcoder.com/forums/?module=Thread&threadID=667388&start=0&mc=5#1209479

using namespace std;

long int Arr[101][101][11];

long int retBox1(int min, int max)
{
	int n=max-min+1;
	return n*(min+max)/2;

}

long int calcMax(long int n1, long int n2)
{
	if(n1>n2)
	return n1;
	else return n2;
}

long int F(int minsaved, int maxdead, int boxleft)
{
	if((maxdead-minsaved)==1)
		return 0;
	if(boxleft==1)
		return retBox1(minsaved+1,maxdead-1);
	
	if(Arr[minsaved][maxdead][boxleft]!=-1) return Arr[minsaved][maxdead][boxleft];
	long int min=LONG_MAX;
	for(int i=minsaved+1;i<maxdead;i++)
	{
		long int f1=F(i,maxdead,boxleft);
		long int f2=F(minsaved,i,boxleft-1);
		long int f3=i+calcMax(f1,f2);
		if(f3<min)
		min=f3;
	}
	Arr[minsaved][maxdead][boxleft]=min;
	return min;
}

int main()
{
//cout<<LONG_MAX;
	int cases;
	cin>>cases;
	while(cases--)
	{
		memset(Arr,-1,sizeof(Arr));
		int k,m;
		cin>>k>>m;
		cout<<F(0,m+1,k)<<endl;
	}
	return 0;
}
