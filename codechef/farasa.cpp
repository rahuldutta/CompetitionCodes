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

//int arr[4000000000];

int main()
{
	//vector<int> ar(900000000,0);
	long long N,i,j;
	vector<long long> arr;
	//map<long long, int> hash;
	cin>>N;
	for(i=0;i<N;i++)
	{
		long long temp;
		cin>>temp;
		arr.push_back(temp);
	}
	long long tot=0;
	for(i=0;i<N;i++)
	{
		long long sum=arr[i];
		/*if(hash.count(sum)<=0)
		{
			hash[sum]=1;
			tot++;
		}*/
		/*if(ar[sum]==0)
		{
			ar[sum]=1;
			tot++;
		}*/
		tot++;
		for(j=i+1;j<N;j++)
		{
			sum+=arr[j];
			/*if(hash.count(sum)<=0)
			{
				hash[sum]=1;
				tot++;
			}*/
			/*if(ar[sum]==0)
			{
				ar[sum]=1;
				tot++;
			}*/
			tot++;
		}
	}
	cout<<tot-1<<endl;
	return 0;
}
