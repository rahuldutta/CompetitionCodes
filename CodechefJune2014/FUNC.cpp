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
#define modNo 1000000007
#define mod 1000000007
#define constX 1e18

using namespace std;

#define getcx getchar_unlocked

int A[10001];
long long store[100001][60];




long long power(long long x, long long y) {
/*
    if(y == 0) return 1;

    long long d = power(x, y>>1)%modNo;
	if(d>=modNo) return 0;
    if((y&1) == 0) return (d*d);
    else return (x*(d*d));
    */
    long long prod=x;
    long long lim=constX/x;
    int i;
    for(i=2;i<=y;i++)
    {
	    prod=prod*x;
    	if(prod>lim) break;
    	
    }
    if(i>=y)
    return prod;
    else return -1;
    
}

void calc()
{
	int endpt=59;
	//std::cout<<LLONG_MAX<<std::endl;
	//const long long constX =1000000000000000000;
	for(long long i=2;i<=100000;i++)	
	{
		int j;
		long long prod=1;
		long long lim=constX/i;
		for(j=1;j<=endpt;j++)
		{
			
			prod=prod*i;
			
			store[i][j]=prod;
			if(prod>lim) break;
		}
		//endpt=(j<=endpt?j:endpt);
	}
		
}



inline void inp(int *n )//fast input function
{
   *n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           *n = (*n<<3)+(*n<<1) + ch-'0', ch=getcx();
   *n=*n*sign;
}
 
inline void inp1(long long int *n )//fast input function
{
   *n=0;
   long long int ch=getcx();long long int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           *n = (*n<<3)+(*n<<1) + ch-'0', ch=getcx();
   *n=*n*sign;
}


int main()
{
	memset(store,0,sizeof(store));
	calc();
	int cases;
	//scanf("%d",&cases);
	inp(&cases);
	while(cases--)
	{
		int N,Q,i,j;
		//scanf("%lld%lld",&N,&Q);
		inp(&N);
		inp(&Q);
		long long ss=0;
		for(i=0;i<N;i++)
		{
			//scanf("%lld",&A[i]);
			inp(&A[i]);
			if(i>=59)
				ss+=A[i];

		}
		ss = (ss < 0) ? ((ss % mod) + mod) : ss % mod;
		for(i=1;i<=Q;i++)
		{
			long long x;
			//scanf("%lld",&x);
			inp1(&x);
			
			long long low=1;
			long long high=x;
			long long ans=(x%modNo)*A[0];
			ans = (ans < 0) ? ((ans % mod) + mod) : ans % mod;	
			
			
			int endpt=N>59?59:N;
			for(j=2;j<=endpt;j++)
			{
				if(j==2)
				{
					low=(long long)(sqrt(x));
					//std::cout<<low<<endl;
				}/*
				else if(j==3)
				{
					low=(long long)(pow(x,1.0/3));
				}*/
				else
				{
					while(low<high)
					{
						long long mid=(low+high)%2==0?(low+high)/2:(low+high+1)/2;
						long long sr;
						if(mid<=100000)
						{
							if(mid==1)
								sr=1;
							else 
								sr=store[mid][j];
						}
						else
							sr=power(mid,j);
						//std::cout<<low<<" "<<high<<"\n";
						//std::cout<<mid<<" "<<sr<<" "<<"\n";
	
						//std::cin.get();
						if(sr<=0 || sr>x)
						{
						//std::cout<<"hello\n";
							high=mid-1;
						}
						else if(sr<x && sr>0)
						{
							low=mid;
						}
						else if(sr==x)
						{
							low=mid;
							break;
						}
						
					}
				}
				//std::cout<<low<<std::endl;
				ans+=(low*A[j-1]);
				ans = (ans < 0) ? ((ans % mod) + mod) : ans % mod;
				
				

				high=low;
				low=1;
				
			}
			ans = ans + ss;
			ans = (ans < 0) ? ((ans % mod) + mod) : ans % mod;	
			printf("%lld",ans);
			if(i!=Q)
				printf(" ");
			else
				printf("\n");
			
			
			
		}
		
	}
	return 0;
}
