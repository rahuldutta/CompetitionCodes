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


int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		double origRate;
		long long origminuites;
		int noofplans,i,j;
		cin>>origRate>>origminuites>>noofplans;
		origRate=floor(origRate*100)/100;
		//cout<<origRate<<endl;

		long double maxCost=origminuites*origRate;
		int pos=0;
		for(i=1;i<=noofplans;i++)
		{
			int M;
			double R;
			double C;
			cin>>M>>R>>C;
			R=floor(R*100)/100;
			long double totCost=C+M*origminuites*R;
			totCost/=M;
			if(totCost<maxCost)
			{
				maxCost=totCost;
				pos=i;
			}
			
		}
	
		
		cout<<pos<<endl;
	}
}
