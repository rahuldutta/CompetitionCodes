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

int sum_weight_upto[33];
int subset_sum[641][641];
int weights[32];

int badness(int a , int b,int c)
{
    int maxx=a>b?a:b;
    maxx=maxx<c?c:maxx;
    int minx=a<b?a:b;
    minx=minx>c?c:minx;
    return maxx-minx;
}


int main()
{
    int cases,no=1;
    scanf("%d",&cases);
    while(cases--)
    {
        int n;
        scanf("%d",&n);
        memset(sum_weight_upto,0,sizeof(sum_weight_upto));
        memset(subset_sum,0,sizeof(subset_sum));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&weights[i]);
            sum_weight_upto[i+1]=sum_weight_upto[i]+weights[i];
            
        }
        
        
        subset_sum[0][0]=1;
        for(int i=0;i<n;i++)
        {
            int weight=weights[i];
            int tot_weight_upto=sum_weight_upto[i+1];
            for(int a=tot_weight_upto;a>=0;a--)
            {
                for(int b=tot_weight_upto;b>=0;b--)
                {
                    if(weight<=a&&subset_sum[a-weight][b]==1)
                        subset_sum[a][b]=1;
                    else if(weight<=b&&subset_sum[a][b-weight]==1)
                        subset_sum[a][b]=1;
                    
                }
            }
        }
        int minx=INT_MAX;
        for(int a =0;a<=sum_weight_upto[n];a++)
        {
            for(int b =0;b<=sum_weight_upto[n];b++)
            {
                if(subset_sum[a][b])
                    minx=min<int>(minx,badness(a,b,sum_weight_upto[n]-a-b));
            }
        }
        
        printf("Case %d: %d\n",no++,minx);
    }
    
    return 0;
    
}