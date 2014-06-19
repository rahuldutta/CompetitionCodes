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

int input[10000];
int disDP[10001];
int revdisDP[10001];


//n^2 solution need a nlogn solution
int lis(int n)
{
	disDP[0]=1;
	revdisDP[n-1]=1;
	for(int i=1,a=n-2;i<n;i++,a--)
	{
		disDP[i]=1;
		revdisDP[a]=1;
		for(int j=0,b=n-1;j<i;j++,b--)
		{
			if(input[i]>input[j]&&(1+disDP[j])>disDP[i])
			{
				disDP[i]=1+disDP[j];
			}
			if(input[a]>input[b]&&(1+revdisDP[b])>revdisDP[a])
			{
				revdisDP[a]=1+revdisDP[b];
			}
		}
	}
	int max_len=1;
	for(int i=0;i<n;i++)
	{
		max_len=max<int>(max_len,min<int>(disDP[i],revdisDP[i]));
	}
	return max_len;
}


int bin_search(int A[], int l, int r, int val)
{
	while(r-l>1)
	{
		int mid=l+(r-l)/2;
		if(A[mid]>=val)
		{
			r=mid;
		}
		else
		{
			l=mid;
		}
	}
	return r;
}

int lis2(int n)
{
	int Aux[10000], Aux1[10000];
	Aux1[0]=input[n-1];
	Aux[0]=input[0];
	disDP[0]=1;
	revdisDP[n-1]=1;
	int len=1,len1=1;
	for(int i=1,j=n-2;i<n;i++,j--)
	{
		if(input[i]<Aux[0])
		{
			Aux[0]=input[i];
			disDP[i]=1;
		}
		else if(input[i]>Aux[len-1])
		{
			Aux[len++]=input[i];
			disDP[i]=len;
		}
		else
		{
			int b=bin_search(Aux,0,len-1,input[i]);
			Aux[b]=input[i];
			disDP[i]=b;
		}
		
		if(input[j]<Aux1[0])
		{
			Aux1[0]=input[j];
			revdisDP[j]=1;
		}
		else if(input[j]>Aux1[len1-1])
		{
			Aux1[len1++]=input[j];
			revdisDP[j]=len1;
		}
		else
		{
			int b=bin_search(Aux1,0,len1-1,input[j]);
			Aux1[b]=input[j];
			revdisDP[j]=b;
		}
		
	}
	int max_len=1;
	for(int i=0;i<n;i++)
	{
		max_len=max<int>(max_len,min<int>(disDP[i],revdisDP[i]));
	}
	return max_len;
}

int main()
{
	int N;
	while(cin>>N)
	{
		memset(input,0,sizeof(input));
		memset(disDP,0,sizeof(disDP));
		memset(revdisDP,0,sizeof(revdisDP));
		for(int i=0;i<N;i++)
		{
			cin>>input[i];
		}
		cout<<(2*lis2(N)-1)<<endl;
	}
	return 0;
}
