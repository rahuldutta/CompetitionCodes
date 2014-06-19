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
	//cout<<cases;
	while(cases--)
	{
		int writers, books;
		cin>>books>>writers;
		long long Arr[500]; 
		int i;
		for(i=0;i<books;i++)
		{
			cin>>Arr[i];
		}
		//cout<<"hello";
		//cin.get();
		long long high=1L<<33;
		long long low=0;
		while(high>low)
		{
			long long mid=(high+low)/2;
			long long accum=0;
			int j=0;
			for(i=0;i<books;i++)
			{
				while(accum+Arr[i]>mid&&j<writers)
				{
					accum=0;
					j++;
				}
				accum+=Arr[i];
			}
			if(j>=writers)
			{
				low=mid+1;
			}
			else
			{
				high=mid;
			}
		}
		long long copy=high;
		//cout<<copy<<endl;
		//cin.get();
		long long accum=0;
		vector<int> start(writers,-1);
		int current = writers-1;
		//cout<<current<<endl;
		//cout<<books<<endl;
		for(i=books-1;i>=0;i--)
		{
			if(accum+Arr[i]>copy)
			{
				accum=0;
				start[current]=i+1;
				//cout<<i<<" "<<start[current]<<endl;
				current--;
			}
			accum+=Arr[i];
		}
		//cout<<current<<endl;
		//cin.get();
		start[current]=0;
		for(i=0;start[i]==-1&&i<writers;i++)
		start[i]=i;
		for(i=0;i<writers-1;i++)
		{
			if(start[i]>=start[i+1])
			{
				start[i+1]=start[i]+1;
			}
		}
		int curr=1;
		for(i=0;i<books;i++)
		{
			cout<<Arr[i];
			if(i!=books-1)
			cout<<" ";
			if(i==start[curr]-1)
			{
				cout<<"/ ";
				curr++;
			}
		}
		cout<<endl;
	}
	return 0;
}
