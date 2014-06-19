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

int maxDP[10001];
int minDP[10001];
int m,n;

/*
tuple<int,int> DP(int T)
{
    //std::cout<<T<<endl;
    if(T==0) return make_tuple(0,0);
    if(T<0) return make_tuple(0,-T);
    if(maxDP[T]!=-1&&minDP[T]!=-1) return make_tuple(maxDP[T],minDP[T]);
    
    auto retVal1=DP(T-m);
    auto retVal2=DP(T-n);
    int burger1=1+get<0>(retVal1);
    int bear1=get<1>(retVal1);
    
    int burger2=1+get<0>(retVal2);
    int bear2=get<1>(retVal2);
    
    if(bear1<bear2)
    {
        minDP[T]=bear1;
        maxDP[T]=burger1;
    }
    else if(bear2<bear1)
    {
        minDP[T]=bear2;
        maxDP[T]=burger2;
    }
    else
    {
        if(burger1>burger2)
        {
            minDP[T]=bear1;
            maxDP[T]=burger1;
        }
        else
        {
            minDP[T]=bear2;
            maxDP[T]=burger2;
        }
    }
    
    return make_tuple(maxDP[T],minDP[T]);
}
*/


vector<int> DP(int T)
{
    //std::cout<<T<<endl;
    vector<int> arr(2);
    if(T==0){ arr[0]=0;arr[1]=0; return arr;}
    if(T<0) {arr[0]=-1;arr[1]=T;return arr;}
        if(maxDP[T]!=-1) {arr[0]=maxDP[T];arr[1]=minDP[T];return arr;}
    
    
    vector<int> retVal1=DP(T-m);
    
    vector<int> retVal2=DP(T-n);
    
    int burger1=1+retVal1[0];
    int bear1=retVal1[1];
    bear1=bear1<0?m+bear1:bear1;
    
    int burger2=1+retVal2[0];
    int bear2=retVal2[1];
    bear2=bear2<0?n+bear2:bear2;
    
    if(bear1<bear2)
    {
        minDP[T]=bear1;
        maxDP[T]=burger1;
    }
    else if(bear2<bear1)
    {
        minDP[T]=bear2;
        maxDP[T]=burger2;
    }
    else
    {
        if(burger1>burger2)
        {
            minDP[T]=bear1;
            maxDP[T]=burger1;
        }
        else
        {
            minDP[T]=bear2;
            maxDP[T]=burger2;
        }
    }
    
    arr[0]=maxDP[T];arr[1]=minDP[T];return arr;
}



int main()
{
    int t;
    while(scanf("%d%d%d",&m,&n,&t)!=EOF)
    {
        //printf("%d,%d,%d\n",m,n,t);
        memset(maxDP,-1,sizeof(maxDP));
        memset(minDP,-1,sizeof(minDP));
        
        
        vector<int> retVal=DP(t);
        long long burger=retVal[0];
        int bear=retVal[1];
        if(bear==0)
            printf("%lld\n",burger);
        else
            printf("%lld %d\n",burger,bear);
        /*
        for(int i=0;i<t;i++)
        {
            
        }*/
        
        
    }
    
    return 0;
}