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
#include<limits.h>

using namespace std;

/*struct pairs
{
	long int n1,n2;
	pairs(long int p1, long int p2): n1(p1), n2(p2)
	{}
	pairs(const pairs& p)
	{
		this->n1=p.n1;
		this->n2=p.n2;
	}
	~pairs(){}
};*/


long int nodes[100000];
long int vals[100000];





// A utility function to find the subset of an element i
int find(long int i)
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
    if(xset!=yset)
	{
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
}

int main()
{
	long int N, M,i,j;
	cin>>N>>M;
	//vector<pairs> pr;
	vector<long int> pr1;
	vector<long int> pr2;
	memset(nodes,-1,sizeof(nodes));
	for(i=0;i<M;i++)
	{
		long int p1,p2;
		cin>>p1>>p2;
		//pr.push_back(pairs(p1-1,p2-1));
		pr1.push_back(p1-1);
		pr2.push_back(p2-1);
	}
	for(i=0;i<N;i++)
	{
		cin>>vals[i];
	}
	for(i=0;i<M;i++)
	{
		long int p1=pr1[i];
		long int p2=pr2[i];
		//if(nodes[p1]!=p2&&nodes[p2]!=p1)
		Union(p1,p2);
		/*for(j=0;j<N;j++)
		{
			cout<<nodes[j]<<endl;
		}
		cin.get();*/
	}
	/*if(pr.size()!=0)
		pr.clear();*/
	if(pr1.size()!=0)
		pr1.clear();
	if(pr2.size()!=0)
		pr2.clear();

	int flag=0;
	long int sum=0;
	long int noof=0;
	/*for(i=0;i<N;i++)
	{
		cout<<nodes[i]<<endl;
	}*/
	long long costmin=LLONG_MAX;
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
			if(vals[i]<costmin)
				costmin=vals[i];
			sum+=vals[i];	
			
		}
	}
	if(noof==1)
		cout<<"0"<<endl;
	else if(flag==1)
		cout<<"-1"<<endl;
	else
	{
		sum+=(noof-2)*costmin;
		cout<<sum<<endl;
	}
	return 0;
}
