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

int arr[]={1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012};

int main()
{
	int flag=false;
	int n;
	while(cin>>n)
	{
		if(flag==true)
		{
			cout<<endl;
		}
		else
			flag=true;
		cout<<arr[n]<<endl;
	}
	return 0;
}
