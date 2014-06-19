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
#define modNo 1000000007
using namespace std;

//long long store[200001][201];
long long store1[200001][201];
int a[200001];
long long powers2[200001];



long long power(long long x, long long y) {
	if(powers2[y]!=-1) return powers2[y];
    if(y == 0) return powers2[y]=1;

    long long d = power(x, y>>1)%modNo;

    if((y&1) == 0) return powers2[y]=(d*d)%modNo;
    else return powers2[y]=(x*(d*d)%modNo)%modNo;
}


/*
long long power()
{
	powers2[0]=1;
	for(long long i=1;i<200001;i++)
	{
		powers2[i]=powers2[i-1]*2;
		if(powers2[i]>=modNo)
		{
			powers2[i]%=modNo;
		}
	}
}
*/

int main()
{
	memset(powers2,-1,sizeof(powers2));
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		power(2,n);
		for(long long i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		long long totPrime=n;
		//memset(store,0,sizeof(store));
		memset(store1,0,sizeof(store1));
		for(long long i=1;i<n;i++)
		{
			vector<int> st;
			vector<int> st1(201,0);
			
			for(long long j=0;j<i;j++)
			{
				int diff=a[i]-a[j]+100;
				if(store1[j][diff]==0)
				{
					//store[i][diff]=2;
					store1[i][diff]++;
				}
				else
				{
					//store[i][diff]=store[j][diff]+1;
					store1[i][diff]+=store1[j][diff]+1;
				}
				/*
				if(store1[j][diff]==0)
					store1[i][diff]++;
				else
					store1[i][diff]+=store1[j][diff];
				*/
				if(st1[diff]==0)
				{
					st.push_back(diff);
					st1[diff]=1;
				}
			}
			for(int pos=0;pos<st.size();pos++)
			{
				totPrime+=store1[i][st[pos]];
				//std::cout<<i<<" "<<" "<<diff<<" "<<totPrime<<std::endl;
				if(totPrime>=modNo)
				{
					totPrime%=modNo;
				}
			}
		}
		//std::cout<<totPrime<<std::endl;
		/*
		for(long long i=1;i<n;i++)
		{
			for(long long diff=0;diff<200;diff++)
			{
				if(store1[i][diff]>=1)
				{
				
					totPrime+=store1[i][diff];
					//std::cout<<i<<" "<<" "<<diff<<" "<<totPrime<<std::endl;
					if(totPrime>=modNo)
					{
						totPrime%=modNo;
					}
				}
			}
		}
		*/
		//std::cout<<n<<" "<<powers2[1]<<std::endl;
		printf("%lld\n",(powers2[n]-totPrime-1)%modNo);
		
	}
	
	
	
	
	
	return 0;
}
