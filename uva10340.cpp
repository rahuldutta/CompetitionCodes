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

string str1;
string str2;
long long ** arr;

long long max(long long l1, long long l2)
{
	return l1>l2?l1:l2;
}

bool DP()
{
	for(int i=0;i<=str1.length();i++)
	{
		for(int j=0;j<=str2.length();j++)
		{
			if(i==0||j==0)
				arr[i][j]=0;
			else
			{
				if(str1[i-1]==str2[j-1])
				{
					arr[i][j]=arr[i-1][j-1]+1;
				}
				else
				{
					arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
				}
			}
		}
	}
	//cout<<arr[str1.length()][str2.length()]<<endl;
	if(arr[str1.length()][str2.length()]== str1.length())
		return true;
		return false;
}

int main()
{
	while(cin>>str1>>str2)
	{
		//cout<<str1<<str2<<endl;
		//cin.get();
		arr= new long long*[str1.length()+1];
		for(int i=0;i<=str1.length();i++)
		{
			arr[i]=new long long[str2.length()+1];
		}
		if(DP())
			cout<<"Yes\n";
		else
			cout<<"No\n";
		for(int i=0;i<=str1.length();i++)
		{
			delete [] arr[i];
		}
		delete [] arr;
	}
	return 0;
}
