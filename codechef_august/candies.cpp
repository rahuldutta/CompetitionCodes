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

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		long long N,K;
		cin>>N>>K;
		if(K==0||N==0)
		{
			cout<<"0 "<<N<<endl;
		}
		else
		{
			cout<<(N/K)<<" "<<(N%K)<<endl;
		}
	}
	return 0;
}
