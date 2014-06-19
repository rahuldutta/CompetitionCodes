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
#define max 100001

using namespace std;

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int N, M, K;
		cin>>N>>M>>K;
		if((M==1&&N==1)||(M==1&&N==2)||(M==2&&N==1))
			cout<<0<<endl;
		else if(N==1||M==1)
		{
			cout<<K<<endl;
		}
		else
		{
			cout<<ceil((double)K/2.0)<<endl;
		}
	}
	return 0;
}
