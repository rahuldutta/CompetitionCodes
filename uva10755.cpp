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
#include <limits.h>

using namespace std;
long long input[20][20][20];
long long inf = -2147483647-1;
//long long inf =0;


long long kadane(long long tmp[], int size )
{
	long long max_ending_so_far=0;
	long long max_so_far=inf;
	
	/*
	cout<<endl;
	for(int j=0;j<size;j++)
	{
		cout<<tmp[j]<<" ";
	}
	cout<<endl;
	*/
	
	for(int i=0;i<size;i++)
	{
		max_ending_so_far+=tmp[i];
		max_ending_so_far=max<long long>(inf,max_ending_so_far);
		max_so_far=max<long long>(max_ending_so_far,max_so_far);
		max_ending_so_far=max<long long>(0,max_ending_so_far);
	}
	//cout<<"1D "<<max_so_far<<endl;
	return max_so_far;
}

long long maximum2D(long long arr[][20], int row, int col)
{
	int left=0,right,k;
	long long tmp[20];
	long long maxsum=inf;
	/*
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(left=0;left<col;left++)
	{
		memset(tmp,0,sizeof(tmp));
		for(right=left;right<col;right++)
		{
			for(k=0;k<row;k++)
			{
				tmp[k]+=arr[k][right];
				//cout<<tmp[k]<<" "<<arr[k][right%size]<<" ";
			}
			maxsum=max<long long>(maxsum,kadane(tmp,row));
			//cout<<endl<<maxsum<<endl;
			//cin.get();
		}
	}
	//cout<<"2D "<<maxsum<<endl;
	//cin.get();
	return maxsum;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int r,c,d;
		cin>>r>>c>>d;
		int i,j,k;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				for(k=0;k<d;k++)
				{
					cin>>input[i][j][k];
				}
			}
		}
		int front=0,end;
		long long tmp2D[20][20];
		long long maxsum=inf;
		for(front=0;front<d;front++)
		{
			memset(tmp2D,0,sizeof(tmp2D));
			for(end=front;end<d;end++)
			{
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						tmp2D[i][j]+=input[i][j][end];
					}
				}
				maxsum=max<long long>(maxsum,maximum2D(tmp2D,r,c));
			}
		}
		cout<<maxsum<<endl;
		cout<<(cases?"\n":"");
	}
	return 0;
}
