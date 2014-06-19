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

long long DP[10001][201];
int pump[10001];


int main()
{
    int cases;
    string line;
    getline(cin,line);
    sscanf(line.c_str(),"%d",&cases);
    getline(cin,line);
    
    while(cases--)
    {
        memset(pump,-1,sizeof(pump));
        long long dist;
        getline(cin,line);
        sscanf(line.c_str(),"%lld",&dist);
        while(getline(cin,line))
        {
            if(line.length()==0)
                break;
            int x, cost;
            sscanf(line.c_str(),"%d%d",&x,&cost);
            
            pump[x]=cost;
            
        }
        
        for(int mile=0;mile<=dist;mile++)
        {
            if(mile==0)
            {
                for(int fuel=0;fuel<=100;fuel++)
                {
                    DP[mile][fuel]=0;
                }
                for(int fuel=101;fuel<=200;fuel++)
                {
                    DP[mile][fuel]=INF;
                }
            }
            else
            {
                
                if(pump[mile]==-1)
            {
                for(int fuel=0;fuel<200;fuel++)
                {
                    DP[mile][fuel]=DP[mile-1][fuel+1];
                }
                DP[mile][200]=INF;
            }
            else
            {
                for(int fuel=0;fuel<200;fuel++)
                {
                    long long a=DP[mile-1][fuel+1];
                    long long b=DP[mile][fuel-1]+pump[mile];
                    DP[mile][fuel]=min<long long>(a,b);
                }
                DP[mile][200]=DP[mile][199]+pump[mile];
            }
            }
        }
        
        if(DP[dist][100]>=INF)
            printf("Impossible\n");
        else
            printf("%lld\n",DP[dist][100]);
        if(cases>=1)
            printf("\n");

    }
    
    return 0;
}