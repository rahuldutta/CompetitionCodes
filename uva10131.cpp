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

int totlength[1001];
int pre[1005];

struct data{
long weight;
long iq;
int id;

data(const data& d)
{
	this->weight=d.weight;
	this->iq=d.iq;
	this->id=d.id;
}

data(long w, long i, int id) : weight(w), iq(i), id(id)
{
}

};

bool compare(const data& a, const data& b)
{
	return a.weight<b.weight;
}

int main()
{
	vector<data> vec;
	long w, i;
	int count=1;
	while(cin>>w>>i)
	{
		vec.push_back(data(w,i,count));
		count++;
	}
	sort(vec.begin(),vec.end(),compare);
	memset(totlength,0,sizeof(totlength));
	memset(pre,-1,sizeof(pre));
	int max=1;
	int pos=0;
	for(int i=1;i<vec.size();i++)
	{
		totlength[i]=1;
		for(int j=0;j<i;j++)
		{
			if(vec[i].weight>vec[j].weight&&vec[i].iq<vec[j].iq)
			{
				if(totlength[j]+1>totlength[i])
				{
					totlength[i]=totlength[j]+1;
					pre[i]=j;
				}
			}
		}
		if(totlength[i]>max)
		{
			max=totlength[i];
			pos=i;
		}
	}
	/*for(int k=0;k<vec.size();k++)
 * 	{
 * 			cout<<vec[k].weight<<" "<<vec[k].iq<<" "<<totlength[k]<<" "<<pre[k]<<endl;
 * 				}*/
	int temp=pos;
	int l=max-1;
	int arr[1005]={0};
	while(pre[temp]!=-1)
	{
		arr[l]=vec[temp].id;
		temp=pre[temp];
		l--;
	}
	arr[l]=vec[temp].id;
	cout<<max<<endl;
	for(int k=0;k<max;k++)
		cout<<arr[k]<<endl;
	
	return 0;	
}
