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
long long X[40];
long long Y[40];

long long power(long long x, long long y, int N) {
    if(y == 0) return 1;

    long long d = power(x, y>>1, N)%N;

    if((y&1) == 0) return (d*d)%N;
    else return (x*(d*d)%N)%N;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		long long upper,d,m,N,actupper;
		cin>>upper>>d>>m>>N;
		int i,j,k;
		actupper=upper>(N-1)?N-1:upper;
		for(j=0;j<=actupper;j++)
		{
			Y[j]=power(j,d,N);
		}
		
		
		
		
		long long increase=upper/N;
		long long increase1=upper%N;
		
		for(i=0;i<=actupper;i++)
		{
			X[i]+=increase;
		}
		for(i=0;i<=increase1;i++)
		{
			X[i]+=1;
		}
		
		long long S=0;
		for(i=0;i<=actupper;i++)
		{
			for(j=0;j<=actupper;j++)
			{
				for(k=0;k<=actupper;k++)
				{
					if((Y[i]+Y[j]+Y[k])%N==m)
					{
						//cout<<i<<" "<<j<<" "<<k<<endl;
						//cin.get();
						S=S+((((X[i]%1000000007)*(X[j]%1000000007))%1000000007)*(X[k]%1000000007))%1000000007;
						S=S%1000000007;
					}
				}
			}
		}
		cout<<S<<endl;
	}
	return 0;
}
