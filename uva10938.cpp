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


int main()
{
	int adj[5000][5000]={{0}};
	int N;
	cin>>N;
	vector< vector<int> > edge(N);
	for(int i=1;i<N;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a-1][b-1]=1;
	}
	
