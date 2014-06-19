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


bool arr[max];
int arr1[max];
vector<long int > primeno;

void generatePrime()
{
	for(long int  i = 0; i < max; ++i)
		arr[i] = true;

	for(long int i = 2; i < max; )
	{
		//mark all multiples
		//cout<<i<<endl;
		primeno.push_back(i);
		arr1[i]=1;
		for(long int j = 2; (j*i) < max; ++j)
		{
			arr[i*j] = false;
			arr1[i*j]++;
		}
		//find next prime
		int flag=0;
		for(long int k = i+1; k < max; k++)
		{
			if(arr[k])
			{				
				i=k;
				flag=1;
				break;
			}	
		}
		if(flag==0)
		break;
	}
}


int main()
{
	generatePrime();
	/*for(int t=0;t<max;t++)
	{
		cout<<t<<" "<<arr1[t]<<endl;
		cin.get();
	}*/
	/*for(int t=0;t<100;t++)
	{
		cout<<primeno[t]<<endl;
	}*/
	/*for(long int i=2;i<=100000;i++)
	{
		int j=0;
		int count=0;
		if(arr[i]==true)
			count=1;
		else
		{
			while(primeno[j]<=(i/2)&&j<primeno.size())
			{
				//cout<<primeno[j]<<" "<<i<<endl;
				if(i%primeno[j]==0)
				count++;
				j++;
			}
		}
		arr1[i]=count;
		//cout<<i<<" "<<arr1[i]<<endl;
		//cin.get();
	}*/
	int cases;
	cin>>cases;
	while(cases--)
	{
		long int A,B,K;
		cin>>A>>B>>K;
		int sum=0;
		for(long int i=A;i<=B;i++)
		{
			if(arr1[i]==K)
			sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
