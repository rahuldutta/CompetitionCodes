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
using namespace std;
//#define INT_MAX 2147483647
//#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
//#define long long LL

#define FOR(a,b) for(int a=0;a<b;a++)
#define FOR1(a,b,c) for(int a=c;a<b;a++)

int main()
{
    map<string, int> mymap;
    string s="";
    long long int sum=1;
    int a,b,c,d,e;
    FOR(a,26)
    {
             s="";
             s.push_back(a+'a');
             mymap[s]=sum++;
    }
    FOR(a,26)
    FOR1(b,26,a+1)
    {
             s="";     
             s.push_back(a+'a');
             s.push_back(b+'a');
             mymap[s]=sum++;
    }
    
    FOR(a,26)
    FOR1(b,26,a+1)
    FOR1(c,26,b+1)
    {
                  s="";     
             s.push_back(a+'a');
             s.push_back(b+'a');
             s.push_back(c+'a');
             mymap[s]=sum++;
    }
    
    FOR(a,26)
    FOR1(b,26,a+1)
    FOR1(c,26,b+1)
    FOR1(d,26,c+1)
    {
             s="";     
             s.push_back(a+'a');
             s.push_back(b+'a');
             s.push_back(c+'a');
             s.push_back(d+'a');
             mymap[s]=sum++;
    }
    
    FOR(a,26)
    FOR1(b,26,a+1)
    FOR1(c,26,b+1)
    FOR1(d,26,c+1)
    FOR1(e,26,d+1)
    {
             s="";     
             s.push_back(a+'a');
             s.push_back(b+'a');
             s.push_back(c+'a');
             s.push_back(d+'a');     
             s.push_back(e+'a');
             mymap[s]=sum++;
    }
    //cout<<sum;
    string ip;
    while(cin>>ip)
    {
                  int i, flag=0;;
                  FOR(i,ip.size()-1)
                  {
                                    if(ip[i+1]<ip[i])
                                    {
                                                       flag=1;break;
                                    }
                  }
                  if(flag==1)
                  cout<<0<<endl;
                  else
                  cout<<mymap[ip]<<endl;
    }
    return 0;
    
}
