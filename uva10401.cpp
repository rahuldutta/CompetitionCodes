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

long long menu[16][16];
int cols[16];
int N;
char IP[16];

bool isplace1(int r1, int r2)
{
    return r2<=r1+1&&r2>=r1-1?false:true;
}

bool isplace2(int r1, int c1)
{
    if(cols[c1+1]<=r1+1&&cols[c1+1]>=r1-1)
        return false;
        return true;
}

void DP()
{
    memset(menu,0,sizeof(menu));
    if(cols[N]!=-1)
        menu[cols[N]][N]=1;
    else
    {
        for(int i=1;i<=N;i++)
            menu[i][N]=1;
    }
    for(int i=N-1;i>=1;i--)
    {
        if(cols[i]!=-1)
        {
            if(!isplace2(cols[i],i))
                continue;
            if(cols[i+1]!=-1)
                menu[cols[i]][i]+=menu[cols[i+1]][i+1];
            else
            {
                for(int k=1;k<=N;k++)
                {
                    if(isplace1(cols[i],k))
                        menu[cols[i]][i]+=menu[k][i+1];
                }
            }

        }
        else
        {
            for(int j=1;j<=N;j++)
            {
                if(!isplace2(j,i))
                    continue;
                if(cols[i+1]!=-1)
                    menu[j][i]+=menu[cols[i+1]][i+1];
                else
                {
                    for(int k=1;k<=N;k++)
                    {
                        if(isplace1(j,k))
                            menu[j][i]+=menu[k][i+1];
                    }
                }
            }
        }
    }
    
}

int main()
{
    while(scanf("%s",IP)!=EOF)
    {
        //cout<<IP<<endl;
        N=strlen(IP);
        for(int i=0;i<N;i++)
        {
            if(IP[i]=='?')
                cols[i+1]=-1;
            else if(isdigit(IP[i]))
            {
                cols[i+1]=IP[i]-'0';
            }
            else
                cols[i+1]=10+IP[i]-'A';
        }
        DP();
        /*
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                printf("%5lld",menu[i][j]);
            }
            printf("\n");
        }
        */
        if(cols[1]==-1)
        {
            long long sum=0;
            for(int i=1;i<=N;i++)
            {
                sum+=menu[i][1];
            }
            printf("%lld\n",sum);
        }
        else
            printf("%lld\n",menu[cols[1]][1]);
    }
    
    return 0;
}