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

long long arr[75][75];
long long tmp[75];

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


long long circularMaximum(long long tmp[], int size)
{
	long long max_sum=kadane(tmp,size);
	long long tot_sum=0;
	long long tmp1[75];
	for(int i=0;i<size;i++)
	{
		tot_sum+=tmp[i];
		tmp1[i]=-tmp[i];
	}
	long long negative_sum=kadane(tmp1,size);
	max_sum=max<long long>(max_sum,(tot_sum+negative_sum));
	return max_sum;	
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
				cin>>arr[i][j];
			}
		}
		

		int left=0,right;
		long long maxsum=0;
		for(left=0;left<size;left++)
		{
			memset(tmp,0,sizeof(tmp));
			for(right=left;right<(left+size);right++)
			{
				for(k=0;k<size;k++)
				{
					tmp[k]+=arr[k][right%size];
					//cout<<tmp[k]<<" "<<arr[k][right%size]<<" ";
				}
				maxsum=max<long long>(maxsum,circularMaximum(tmp,size));
				//cout<<endl<<maxsum<<endl;
				//cin.get();
			}
		}
		cout<<maxsum<<endl;
	}
	return 0;
}
