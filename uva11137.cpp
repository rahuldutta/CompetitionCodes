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

using namespace std;


vector< vector<long int> > sumCheck(int Arr[], int size, int sum)
{
	//cout<<sum<<endl;
	//cin.get();

	vector< vector<long int> > count;

	vector<long int> tmp1;

	tmp1.assign(sum+1, 0);
	int i,j;
	for(i =0; i<=size;i++)
	{

		count.push_back(tmp1);
		for(j=0; j<=sum; j++)
		{
			if(i==0&&j!=0)
			{
				count[i][j]=0;
			}
			else if(j==0)
			{

				count[i][j]=1;
			}
			else
			{
				count[i][j]=count[i-1][j];
				if((j-Arr[i-1])>=0)
				{
					count[i][j]=count[i-1][j]+count[i][j-Arr[i-1]];
					
				}
			}

		}
	}
	//for()
	
	//cout<<count[size][sum];
	return count;
}

int main()
{
	int noofcases,i,j,arr[21];
	for(i=0;i<21;i++)
	{
		arr[i]=(i+1)*(i+1)*(i+1);
	}
	vector< vector<long int> > t=sumCheck(arr,21,10000);
	string line;
	while(getline(cin,line))
	{
		stringstream iss;
		iss.clear();
    	iss.str("");
    	iss<<line;
    	int N;
    	iss>>N;
    	cout<<t[21][N]<<endl;
	}
}
