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

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
long long multDP[100001][25];
long long arr[100][25];
int vis[100];
int input[100000];
//long long ar[1000000];


int mod_bld(long long x, long long y)
{
    long long modulus = x, divisor = y;

    while (divisor <= modulus && divisor <= LLONG_MAX/2)
        divisor <<= 1;

    while (modulus >= y) {
        while (divisor > modulus)
            divisor >>= 1;
        modulus -= divisor;
    }

    return modulus;
}

long long power(long long x, long long y, long long N) {
    if(y == 0) return 1;

    long long d = power(x, y>>1, N);
    d=d%N;
    long long sq=(d*d)%N;
    if((y&1) == 0)
    {
    	//ar[y]=sq;
    	return sq;
    }
    else 
    {
    	//ar[y]=((x*sq)%N);
    	return ((x*sq)%N);
    }
    //return ar[y];
}


long long expo(long long a, long long b, long long mod1){
  long long result = 1;

  while (b){
    if (b&1){
      result *= a;
      result %=mod1;
    }
    b >>=1 ;
    a *=a;
    a %= mod1;
  }

  return result;
}


int main()
{
	/*
	long long ts=1;
	for(long long t=1;t<=100000;t++)
	{
		ts=((ts%999999999)*(11))%999999999;
	}
	cout<<ts<<endl;
	*/
	
	long long N;
	scanf("%lld",&N);
	memset(vis,0,sizeof(vis));
	memset(arr,0,sizeof(arr));
	memset(multDP,0,sizeof(multDP));
	long long i,j,k;
	
	
	for(i=0;i<N;i++)
	{
		scanf("%d",&input[i]);
		if(!vis[input[i]-1])
		{
			int temp=input[i];
			j=0;
			while(temp!=1)
			{
				while(temp%prime[j]==0)
				{
					arr[input[i]-1][j]+=1;
					temp/=prime[j];
				}
				j++;
			}
			vis[input[i]-1]=1;
		}
	}
	vector<int> nonzero;
	for(i=1;i<=N;i++)
	{
		for(j=0;j<25;j++)
		{
			multDP[i][j]=multDP[i-1][j]+arr[input[i-1]-1][j];
			if(i==N&&multDP[i][j]!=0)
			{
				nonzero.push_back(j);
			}
		}
	}
	/*
	for(i=0;i<=N;i++)
	{
		for(j=0;j<25;j++)
		{
			cout<<multDP[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	long long T;
	scanf("%lld",&T);
	for(i=0;i<T;i++)
	{
		long long L,R,mod1;
		scanf("%lld %lld %lld",&L,&R,&mod1);
		long long S=1;
		bool flag=false;
		for(j=0;j<nonzero.size();j++)
		{
			int pos=nonzero[j];
			long long temp=multDP[R][pos]-multDP[L-1][pos];
			if(temp!=0)
			{
				flag=true;

				S*=(expo(prime[pos],temp,mod1));
				//printf("%d %lld\n",prime[j], te);
				S=S%mod1;
			}
			
		}
		//cout<<i<<endl;
		if(flag)
		{
			printf("%lld\n",S);
			//cout<<S<<endl;
		}
		else
		{
			printf("%lld\n",1%mod1);
			//cout<<(1%mod1)<<endl;
		}
			
		
	}
	return 0;
}
