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

long long arr[100][100];
long long tmp[100];

long long kadane(long long tmp[], int size )
{
	long long max_ending_so_far=0;
	long long max_so_far=0;
	for(int i=0;i<size;i++)
	{
		max_ending_so_far+=tmp[i];
		max_ending_so_far=max<long long>(0,max_ending_so_far);
		max_so_far=max<long long>(max_ending_so_far,max_so_far);
	}
	return max_so_far;
}

int main()	
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int size;
		cin>>size;
		int i,j,k;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
			{
				arr[i][j]=1;
			}
		}
		int b;
		cin>>b;
		for(i=0;i<b;i++)
		{
			int r1,c1,r2,c2;
			cin>>r1>>c1>>r2>>c2;
			for(j=r1-1;j<=r2-1;j++)
			{
				for(k=c1-1;k<=c2-1;k++)
				{
					arr[j][k]=-10000;
				}
			}
		}
		int left=0,right;
		long long maxsum=0;
		for(left=0;left<size;left++)
		{
			memset(tmp,0,sizeof(tmp));
			for(right=left;right<size;right++)
			{
				for(k=0;k<size;k++)
				{
					tmp[k]+=arr[k][right%size];
					//cout<<tmp[k]<<" "<<arr[k][right%size]<<" ";
				}
				maxsum=max<long long>(maxsum,kadane(tmp,size));
				//cout<<endl<<maxsum<<endl;
				//cin.get();
			}
		}
		cout<<maxsum<<endl;
	}
	return 0;
}
