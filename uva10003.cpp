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
#include<climits>

using namespace std;
long long Arr[1001][1001];
long long Arr1[51][51];

long long F2(int st, int end, int a[])
{
	if((end-st)<=1)
	return 0;
	if(Arr1[st][end]!=-1)
	return Arr1[st][end];
	long long min = LLONG_MAX;
	for(int i=st+1;i<end;i++)
	{
		long long S=a[end]-a[st]+F2(i,end,a)+F2(st,i,a);
		if(S<min)
		min=S;
	}
	Arr1[st][end]=min;
	return Arr1[st][end];
}

long long F1(int n1, int n2,int i,int j,int a[])
{
	if(i>j)
	return 0;
	if(i==j)
	return n2-n1;
	if(Arr[n1][n2]!=-1)
	return Arr[n1][n2];
	long long min = LLONG_MAX;
	for(int k=i;k<=j;k++)
	{
		long long S=F1(n1,a[k],i,k-1,a)+F1(a[k],n2,k+1,j,a);
		if(S<min)
		min=S;
	}
	Arr[n1][n2]=min+n2-n1;
	return Arr[n1][n2];
}

long long F(int n, int i, int j, int st,int a[])
{
	if(i>j)
	return 0;
	if(i==j)
	return n;
	long long min = LLONG_MAX;
	for(int k=i;k<=j;k++)
	{
		long long S=n+F(a[k]-st,i,k-1,st,a)+F(n-a[k]+st,k+1,j,a[k],a);
		if(S<min)
		min=S;
	}
	return min;
}

int main()
{
/*
	int l;
	while(cin>>l)
	{
		if(l==0)
		break;
		memset(Arr,-1,sizeof(Arr));
		int n;
		cin>>n;
		int arr[50];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		//cout<<"The minimum cutting is "<<F(l,0,n-1,0,arr)<<"."<<endl;	
		cout<<"The minimum cutting is "<<F1(0,l,0,n-1,arr)<<"."<<endl;	
	}
*/
	int l;
	while(cin>>l)
	{
		if(l==0)
		break;
		int n;
		memset(Arr1,-1,sizeof(Arr1));
		cin>>n;
		int arr[52];
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		arr[0]=0;
		arr[n+1]=l;
		cout<<"The minimum cutting is "<<F2(0,n+1,arr)<<"."<<endl;
	}
	return 0;
}
	
