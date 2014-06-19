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

int Element[40][4];
int Map[40][40][40][40];
int count(int arr[])
{
	int cnt=0;
	for(int j=0;j<20;j++)
	{
		if(arr[j])
		cnt++;
	}
	return cnt;
}


int func(int a, int b, int c, int d, int arr[], int piles)
{
	if(count(arr)==5||(a>=piles&&b>=piles&&c>=piles&&d>=piles))
	{
		/*for(int j=0;j<20;j++)
		cout<<arr[j]<<" ";
		cout<<endl;*/

		//cout<<sum<<endl;
		return 0;
	}
	
	if(Map[a][b][c][d]!=-1) return Map[a][b][c][d];
	
	int maxe[4]={0};
	if(a<piles)
	{
		int t=0;
		arr[Element[a][0]-1]^=1;
		if(arr[Element[a][0]-1]==0) t=1;
		maxe[0]=func(a+1,b,c,d,arr,piles)+t;
		arr[Element[a][0]-1]^=1;
	}
	if(b<piles)
	{
		int t=0;
		arr[Element[b][1]-1]^=1;
		if(arr[Element[b][1]-1]==0) t=1;
		maxe[1]=func(a,b+1,c,d,arr,piles)+t;
		arr[Element[b][1]-1]^=1;
	}
	if(c<piles)
	{
		int t=0;
		arr[Element[c][2]-1]^=1;
		if(arr[Element[c][2]-1]==0) t=1;
		maxe[2]=func(a,b,c+1,d,arr,piles)+t;
		arr[Element[c][2]-1]^=1;
	}
	if(d<piles)
	{
		int t=0;
		arr[Element[d][3]-1]^=1;
		if(arr[Element[d][3]-1]==0) t=1;
		maxe[3]=func(a,b,c,d+1,arr,piles)+t;
		arr[Element[d][3]-1]^=1;
	}
	int max=0;
	for(int i=0;i<4;i++)
	{
		if(maxe[i]>max)
		max=maxe[i];
	}
	Map[a][b][c][d]=max;
	return max;
}

int main()
{
	int piles=0;
	bool flag=false;
	while(cin>>piles)
	{
		/*if(flag) cout<<endl;
		else flag=true;*/
		if(piles==0)
		break;
		memset(Element,0,sizeof(Element));
		memset(Map,-1,sizeof(Map));
		for(int i=0;i<piles;i++)
		{
			cin>>Element[i][0];
			cin>>Element[i][1];
			cin>>Element[i][2];
			cin>>Element[i][3];
		}
		int arr[20]={0};
		
		//cout<<"hello"<<endl;
		cout<<func(0,0,0,0,arr,piles)<<endl;
	}
	return 0;
}
