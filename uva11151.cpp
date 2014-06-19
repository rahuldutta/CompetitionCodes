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

int palindromeLength(string str)
{
	int arr[1000][1000];
	int i,j;
	for(j=0;j<str.length();j++)
	for(i=0;i<str.length()-j;i++)
	{
		int first=i;
		int last=i+j;
		if(j==0)
		{
			arr[first][last]=1;
		}
		else
		{
			if(str[first]==str[last])
			{
				if((last-first)==1)
				{
					arr[first][last]=2;
				}
				else
				{
					arr[first][last]=arr[first+1][last-1]+2;
				}
			}
			else
			{
				int one=arr[first][last-1];
				int two=arr[first+1][last];
				if(one>two)
				arr[first][last]=one;
				else
				arr[first][last]=two;
			}
		}
	}
	return arr[0][str.length()-1];
}


int main()
{
	string line;
	getline(cin,line);
	stringstream iss;
	iss.clear();
    iss.str("");
    iss<<line;
    int T;
    iss>>T;
	for(int i=0;i<T;i++)
	{
		string s;
		getline(cin,s);
		if(s.length()==0)
		cout<<0<<endl;
		else
		cout<<palindromeLength(s)<<endl;
	}
}
