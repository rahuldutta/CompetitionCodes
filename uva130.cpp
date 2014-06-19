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


typedef long long int int64;
using namespace std;
/*
int64 Josephus(int64 n, int64 k)
{
	if(n==1)
	return 0;
	else
	return (Josephus(n-1,k)+k)%n;
}

int main()
{
	int64 N,K;
	
	while(true)
	{
		cin>>N>>K;
		if(N==0&&K==0)
		{
			break;
		}
		cout<<Josephus(N,K)<<endl;
	}
	return 0;
}*/

int main()
{
	int64 N,K;

	
	while(true)
	{
		cin>>N>>K;
		if(N==0&&K==0)
		{
			break;
		}
		vector<int> mylist;
		for(int i=1;i<=N;i++)
		{
			mylist.push_back(i);
		}
		int temp=0,k=K;
		while(mylist.size()!=1)
		{
			
			temp=(temp+k-1)%(mylist.size());
			mylist.erase(mylist.begin()+temp);
			int pos=(temp+k-1)%(mylist.size());
			//cout<<temp<<" "<<pos<<endl;
			mylist.insert(mylist.begin()+temp,mylist[pos]);
			if(temp<=pos)
			pos++;
			mylist.erase(mylist.begin()+pos);
			if(pos<temp)
			temp--;
			temp=(temp+1)%(mylist.size());
			/*for(int l=0;l<mylist.size();l++)
			{
				cout<<mylist[l]<<" ";
			}*/
			//cout<<endl;
			
			//cin.get();
				
		}
		//temp=(temp+k-1)%(mylist.size());
		//mylist.erase(mylist.begin()+temp);
		int hl=mylist[0];
		//cout<<hl<<endl;
		if(hl==1)
		cout<<1<<endl;
		else
		cout<<((1+N)-(hl-1))<<endl;
		
	}
	return 0;
}
