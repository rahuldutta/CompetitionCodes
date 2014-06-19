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
int roomArray[100];



bool myfunction (int i,int j) { return (i>j); }


int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int n,m,i,j,k;
		cin>>n>>m;
		memset(roomArray,0,sizeof(roomArray));
		//vector<int> roomVisit;
		for(i=0;i<m;i++)
		{
			int visit;
			cin>>visit;
			/*
			if(roomArray[visit]<=0)
			{
				roomVisit.push_back(visit);
				roomArray[visit]++;
			}
			else
			{
				roomArray[visit]++;
			}*/
			roomArray[visit]++;
		}
		long long totVol=0;
		for(i=0;i<n;i++)
		{
			int noofbottles;
			cin>>noofbottles;
			vector<long long> bottleVol;
			for(j=0;j<noofbottles;j++)
			{
				long long v;
				cin>>v;
				bottleVol.push_back(v);
			}
			if(roomArray[i]>0)
			{
				sort(bottleVol.begin(), bottleVol.end(),myfunction);
				for(k=0;k<roomArray[i]&&k<bottleVol.size();k++)
				{
					totVol+=bottleVol[k];
				}
			}
		}
		cout<<totVol<<endl;
	}
	return 0;
}
