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

using namespace std;

int Arr[10005][101];

int mod(int a, int b) {
        if (a < 0)
            a = a + (-a / b + 1) * b;
        return a % b;
    }

int DP(int S,int arr[],int K, int st, int length)
{
	if(st==length)
		return S==0;
	if(Arr[st][S]!=-1) return Arr[st][S];
	return Arr[st][S]=DP(mod((S+arr[st]),K),arr,K,st+1,length) | DP(mod((S-arr[st]),K),arr,K,st+1,length);
}


int main()
{
	//int t1=-23;
	//cout<<(t1%5);
	int cases;
	cin>>cases;
	while(cases--)
	{
		int N,K;
		cin>>N>>K;
		int arr[10000];
		memset(Arr,-1,sizeof(Arr));
		for(int i=0;i<N;i++)
		{
			int temp;
			cin>>temp;
			arr[i]=temp;//mod(temp,K);
		}
		/*if(N==1)
		{
			if(arr[0]%K==0)
				cout<<"Divisible\n";
			else
				cout<<"Not Divisible\n";
				
		}*/
		if(DP(mod(arr[0],K),arr,K,1,N))
			cout<<"Divisible\n";
		else
			cout<<"Not divisible\n";
	
	}
	return 0;
}
