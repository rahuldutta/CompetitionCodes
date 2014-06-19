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
#include<climits>

using namespace std;
long long DP[501][501];
int arr[501];

int main()
{
	int cases;
	cin>>cases;
	int count=1;
	while(cases--)
	{
		int n,k;
		cin>>n>>k;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
		{
			arr[i]=i+1+k;
		}
		memset(DP,0,sizeof(DP));
		
		for(int d=2;d<=n;d++)
		{
			//cout<<"hello";
			for(int l=1;l+d-1<=n;l++)
			{
				int r = l+d-1;
				long long min=LLONG_MAX;
				long long ans;
				for(int mid=l;mid<=r;mid++)
				{
					ans=DP[l][mid-1]+arr[mid-1]*d+DP[mid+1][r];
					if(ans<min)
						min=ans;
				}
				DP[l][r]=min;
			}
		}
		cout<<"Case "<<count<<": "<<DP[1][n]<<"\n";
		count++;
	}
		
}
