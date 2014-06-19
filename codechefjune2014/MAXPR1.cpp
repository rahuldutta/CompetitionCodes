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

//long long store[21][201];
long long store1[101][101];
long long store2[101][101];
long long numb[101];
int a[200001];
long long powers2[200001];



long long power(long long x, long long y) {
	
    if(y == 0) return powers2[y]=1;
    if(powers2[y]!=-1) return powers2[y];
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
    /*
    power(2,15);
    power(2,32);
    cout<<powers2[15]<<endl;
    cout<<powers2[32]<<endl;
	*/
     int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		long long pw=power(2,n);
        /*
        for (long long i=1;i<=n;i++)
        {
            pw = pw + pw;
            if (pw >= modNo) pw -= modNo;
        }*/
		for(long long i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		long long totPrime=n;
		//memset(store,0,sizeof(store));
		memset(store1,0,sizeof(store1));
        memset(store2,0,sizeof(store2));
        memset(numb,0,sizeof(numb));
		for(long long i=0;i<n;i++)
		{
			
			int no=a[i];
			for(long long diff1=0;diff1<=100;diff1++)
			{
                if(no-diff1>0&&no-diff1<=100)
                {
                    long long r=(store1[no-diff1][diff1]+numb[no-diff1]);
                    if(r>=modNo)r-=modNo;
                    store1[no][diff1]+=r;
                    if(store1[no][diff1]>=modNo)store1[no][diff1]-=modNo;
                }
			}
            
            for(long long diff2=1;diff2<=100;diff2++)
			{
                if(no+diff2<=100&&no+diff2>0)
                {
                    long long r=(store2[no+diff2][diff2]+numb[no+diff2]);
                    if(r>=modNo)r-=modNo;
                    store2[no][diff2]+=r;
                    if(store2[no][diff2]>=modNo)store2[no][diff2]-=modNo;
                }
			}
            
            numb[no]++;
            /*
            for(int k=0;k<=4;k++)
            {
                for(int j=0;j<=4;j++)
                {
                    cout<<store1[k][j]<<" ";
                }
                cout<<endl;
                
            }
            std::cout<<endl;
            */
			
		}
        
        
        
        
        for(int i=0;i<=100;i++)
        {
            for(int j=0;j<=100;j++)
            {
                totPrime=(totPrime+store1[i][j]);
                if(totPrime>=modNo)totPrime-=modNo;
                /*
                if(totPrime>=modNo)
                {
                    totPrime%=modNo;
                }*/
                totPrime=(totPrime+store2[i][j]);
                if(totPrime>=modNo)totPrime-=modNo;
                /*if(totPrime>=modNo)
                {
                    totPrime%=modNo;
                }*/
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
        pw=pw-totPrime-1;
        if(pw<0)pw+=modNo;
		printf("%lld\n",pw);
		
	}
	
	
	
	
	
	return 0;
}
