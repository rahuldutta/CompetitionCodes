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
long long arr[101];
long long sign[101];
long long prod;
int storeVals[65000][101];

int DP(long long S,int k, int len)
{
	if(k==len)
	{
		if(S==prod)
			return 1;
		else
			return 0;
	}
	if(storeVals[S+32000][k]!=-1)
		return storeVals[S+32000][k];
	int result=0;
	if(S+arr[k]>=-32000&&S+arr[k]<=32000)
	{
		result=DP(S+arr[k],k+1,len);
		
		if(result)
		{
			storeVals[S+32000][k]=result;
			sign[k-1]=1;
			return result;
		}
	}
	if(S-arr[k]>=-32000&&S-arr[k]<=32000)
	{
		result=DP(S-arr[k],k+1,len);
		
		if(result)
		{
			storeVals[S+32000][k]=result;
			sign[k-1]=2;
			return result;
		}
	}
	if(S*arr[k]>=-32000&&S*arr[k]<=32000)
	{
		result=DP(S*arr[k],k+1,len);
		
		if(result)
		{
			storeVals[S+32000][k]=result;
			sign[k-1]=3;
			return result;
		}
	}
	if(S%arr[k]==0&&S/arr[k]>=-32000&&S/arr[k]<=32000)
	{
		result=DP(S/arr[k],k+1,len);
		
		if(result)
		{
			storeVals[S+32000][k]=result;
			sign[k-1]=4;
			return result;
		}
	}
	storeVals[S+32000][k]=result;
	return result;


}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		memset(arr,0,sizeof(arr));
		memset(sign,0,sizeof(sign));
		memset(storeVals,-1,sizeof(storeVals));
		int p;
		cin>>p;
		for(int i=0;i<p;i++)
		{
			cin>>arr[i];
		}
		cin>>prod;
		if(DP(arr[0],1,p))
		{
			cout<<arr[0];
			for(int i=1;i<p;i++)
			{
				switch(sign[i-1])
				{
					case 1:cout<<"+";
						   break;
					case 2:cout<<"-";
						   break;
					case 3:cout<<"*";
						   break;
					case 4:cout<<"/";
						   break;			
				}
				cout<<arr[i];
			}
			cout<<"="<<prod<<endl;
		}
		else
		{
			cout<<"NO EXPRESSION"<<endl;
		}
	}
	return 0;
}
