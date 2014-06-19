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
#define INF 40000000

using namespace std;

long long DP[100][100];
int IP[100][100];
int R,C;

void resetDP()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            DP[i][j]=0;
        }
    }
}

long long calcDP(int r, int c)
{
    if(DP[r][c]>0) return DP[r][c];
    long long lmax=1;
    if(r+1<R&&IP[r][c]>IP[r+1][c])
    {
        lmax=max<long long>(lmax,1+calcDP(r+1,c));
    }
    if(c+1<C&&IP[r][c]>IP[r][c+1])
    {
        lmax=max<long long>(lmax,1+calcDP(r,c+1));
    }
    
    if(r-1>=0 && IP[r][c]>IP[r-1][c])
    {
        lmax=max<long long>(lmax,1+calcDP(r-1,c));
    }
    if(c-1>=0 && IP[r][c]>IP[r][c-1])
    {
        lmax=max<long long>(lmax,1+calcDP(r,c-1));
    }
    
    DP[r][c]=lmax;
    return lmax;
}


int main()
{
    
    int cases;
    scanf("%d",&cases);

    while(cases--)
    {
        char nameP[1000];
        scanf("%s",nameP);
        scanf("%d",&R);
        scanf("%d",&C);
        resetDP();
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                scanf("%d",&IP[i][j]);
            }
        }
        long long maxL=0;
        
        for(int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                maxL=max<long long>(maxL,calcDP(i,j));
            }
        }
        
        
        printf("%s: %lld\n",nameP,maxL);
        
    }
    return 0;
}
