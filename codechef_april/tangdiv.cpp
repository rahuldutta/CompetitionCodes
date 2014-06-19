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
#define MAXK 500
struct entry{
long long low;
long long high;
entry()
{
	low=0;
	high=0;
}
};

bool cmp(struct entry a, struct entry b){
	if(a.high<b.low) return true;
	else
	return false;
}
long long l_cross=0,h_cross=0;
int checkSpecialRange(long long l,long long h)
{
	if(l<=h)
	{
		if(l<=h_cross&&h>h_cross)
			return -1;
		if(h>=l_cross&&l<l_cross)
			return -1;
		if(l<=h_cross&&h<=h_cross)
			return 1;
			else if(l>=l_cross&&h>=l_cross) return 1;
			else
			return 0;
	}
	else
	{
		if(l>=l_cross&&h<=h_cross)
		{
			return 1;
		}
		else
		return -1;
	}
	

	
}

int checkRange(long long l, long long h, struct entry& a)
{
	if(l<=h)
	{
		if(l>=a.low&&h<=a.high)
		{
			return 1;
		}
		else return -1;
	}
	else
	return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	vector<struct entry> K(501);
		vector<struct entry> P(501); 
	while(T--)
	{
		
		long long n,k,p,i=0,j=0,c=0;
		scanf("%lld %lld %lld",&n,&k,&p);
		
		for(i=0;i<k;i++)
		{
			long long l,h;
			scanf("%lld %lld",&l,&h);
			K[i].low=l;
			K[i].high=h;
		}
		
		int flag=0;
		for(c=0;c<p;c++)
		{
			long long l,h;
			scanf("%lld %lld",&l,&h);
			if(l>h)
			{
				l_cross=l;
				h_cross=h;
			}
			else
			{
				P[j].low=l;
				P[j].high=h;
				j++;
			}
			
		}
		if(j>0)
			sort(P.begin(),P.begin()+j,cmp);
		/*
		for(int t=0;t<j;t++)
		{
			cout<<P[t].low<<" "<<P[t].high<<endl;
		}*/
		//cout<<j<<" hello "<<p<<endl;
		for(i=0;i<k;i++)
		{
			long long l=K[i].low,h=K[i].high;
			//cout<<l<<" hello "<<h<<endl;
			if(j<p)
			{
				if(checkSpecialRange(l,h)==-1)
				{
					flag=1;
					break;
				}
				else if(checkSpecialRange(l,h)==1)
					continue;
			}
			if(l<=h)
			{
				long long lr=0,hr=j-1;	
				while(lr<=hr)
				{
					long long mid=(lr+hr)/2;
					//cout<<mid<<endl;
					if(h<P[mid].low)
					{
						hr=mid-1;
					}
					else if(l>P[mid].high)
					{
						lr=mid+1;
					}
					else
					{
						if(checkRange(l, h, P[mid])==1)
						{
						
						}
						else
						{
							flag=1;
						}
						break;
					}
				}
				if(lr>hr)
					flag=1;
				if(flag==1)
				break;	
			}
			else
			{
				flag=1;
				break;
			}
			
		}
		if(flag)
		{
			printf("No\n");
		}
		else
			printf("Yes\n");
			
	}
	
	return 0;
}
