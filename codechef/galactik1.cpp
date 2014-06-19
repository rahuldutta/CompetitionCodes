#include <iostream>
#include <fstream>
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

int nodes[100005];
long int vals[100005];

// A utility function to find the subset of an element i
int find(int i)
{
    if (nodes[i] == -1)
        return i;
    return nodes[i]= find(nodes[i]);
}
 
// A utility function to do union of two subsets 
void Union(long int x, long int y)
{
    long int xset = find(x);
    long int yset = find(y);
    if(vals[xset]<0&&vals[yset]<0)
    	nodes[xset] = yset;
    else if(vals[xset]>=0&&vals[yset]>=0)
    {
    	if(vals[xset]<vals[yset])
    		nodes[yset]=xset;
    	else
    		nodes[xset]=yset;
    }
    else if(vals[xset]<0)
    	nodes[xset]=yset;
    else
    	nodes[yset]=xset;
}
int main()
{
	memset(nodes,-1,sizeof(nodes));
	long int N, M,i,j;
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		long int p1,p2;
		cin>>p1>>p2;
	}
	for(i=0;i<N;i++)
	{
		cin>>vals[i];
	}
	cin.seekg(0, cin.beg);
	cin>>N>>M;
	//cout<<M<<" "<<N<<endl;
	for(i=0;i<M;i++)
	{
		long int p1,p2;
		cin>>p1>>p2;
		//cout<<p1<<" "<<p2<<endl;
		if(nodes[p1-1]!=(p2-1)&&nodes[p2-1]!=(p1-1))
			Union(p1-1,p2-1);
	}
	int flag=0;
	long int sum=0;
	long int noof=0;
	/*for(i=0;i<N;i++)
	{
		cout<<nodes[i]<<endl;
	}*/
	for(i=0;i<N;i++)
	{
		if(nodes[i]==-1)
		{
			noof++;
			if(vals[i]<0)
			{
				flag=1;
				if(noof>1)
					break;
			}
			sum+=vals[i];	
			
		}
	}
	if(noof==1)
		cout<<"0"<<endl;
	else if(flag==1)
		cout<<"-1"<<endl;
	else
		cout<<sum<<endl;
	return 0;
}
	
