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


bool sumCheck(int Arr[], int size, int sum)
{
	//cout<<sum<<endl;
	//cin.get();
	bool truth[21][101];
	for(int i =0; i<=size;i++)
	{
		for(int j=0; j<=sum; j++)
		{
			if(i==0&&j!=0)
			truth[i][j]=false;
			else if(j==0)
			truth[i][j]=true;
			else
			{
				if((j-Arr[i-1])>=0)
				truth[i][j]=truth[i-1][j] || truth[i-1][j-Arr[i-1]];
				else
				truth[i][j]=truth[i-1][j];
			}
			//cout<<truth[i][j]<<" "<<i<<" "<<j<<endl;
			//cin.get();
		}
	}
	//cout<<"hello";
	return truth[size][sum];
}

int main()
{
	int noofturns;
	string line;
	stringstream iss;
	getline(cin, line);
	iss.clear();
    	iss.str("");
    	iss << line;
    	iss>>noofturns;
	//cout<<noofturns<<endl;
	int count=0;
	
	while(count<noofturns)
	{
		//cout<<count<<endl;
		int arr[20];
		
		getline(cin, line);
		
		iss.clear();
    	iss.str("");
    	iss << line;
    	int index=0;
    	int Sum=0;
    	while(!iss.eof())
		  {
			if(isspace(iss.peek()))
			  iss >> ws;
			else
			{
			  iss>>arr[index];
			  Sum+=arr[index];
			  index++;
			  }			
		  }
		  //cout<<index;
		  //cin.get();
		  if(Sum%2!=0)
		  {
		  	cout<<"NO"<<endl;
		  }
		  else
		  {
		  	if(sumCheck(arr,index,Sum/2)==true)
		  	cout<<"YES"<<endl;
		  	else
		  	cout<<"NO"<<endl;
		  }
		  count++;
		  //if(count!=noofturns)
		  //cout<<endl;
		
	}
	
}
