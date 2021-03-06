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
#define N 1000000
using namespace std;
int MAXNODES;

int BS(int node, int balls)
{
	int right=2*node+1;
	int left=2*node;
	if(right<=MAXNODES && left <= MAXNODES)
	{
	if(balls%2==0)
	BS(right, balls/2);
	else 
	BS(left, balls/2+1);
	}
	else
	{
	return node;
	}
	
}

int main()
{

	long int T;
	while(cin>>T)
	{
	if(T==-1)
	{
	break;
	}
	while(T--)
	{
	long int D,I;
	cin>>D>>I;
	MAXNODES=pow(2,D)-1;
	cout<<BS(1,I)<<"\n";
	}
	}
	return 0; 
}
