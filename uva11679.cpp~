#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
 

using namespace std;

long int reserves[20];
int main()
{
	int B;
	int N;
	while(cin>>B>>N)
	{
	if(N==0&&B==0)
	{
	break;
	}
	for(int k=0;k<B;k++)
	cin>>reserves[k];
	int flag=0;
	for(int j=0;j<N;j++)
	 {
	 	int d,c;
	 	long double temp;;
	 	cin>>d>>c>>temp;
	 	reserves[d-1]-=temp;
	 	reserves[c-1]+=temp;
	 }
	 for(int i=0;i<B;i++)
	 if(reserves[i]<0)
	 {
	 cout<<"N\n";
	 flag=-1;
	 break;
	 }
	 if(flag!=-1)
	 {
	 cout<<"S\n";
	 }
	}
	return 0;
}
