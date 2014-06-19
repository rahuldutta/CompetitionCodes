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


vector< vector<bool> > sumCheck(int Arr[], int size, int sum)
{
	//cout<<sum<<endl;
	//cin.get();
	vector< vector<bool> > truth;
	vector<bool> tmp;
	tmp.assign(sum+1, true);
	
	for(int i =0; i<=size;i++)
	{
		truth.push_back(tmp);
		for(int j=0; j<=sum; j++)
		{
			//cout<<"hello1";
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
	return truth;
}
int main()
{
	string line;
	while(getline(cin,line))
	{
		stringstream iss;
		iss.clear();
    	iss.str("");
    	iss<<line;
    	int N;
    	iss>>N;
    	int nooftracks;
    	iss>>nooftracks;
    	int arr[20],i;
    	for(i=0;i<nooftracks;i++)
    	{
    		iss>>arr[i];
    	}
    	//cout<<N<<nooftracks<<endl;
    	vector< vector<bool> > tr=sumCheck(arr,nooftracks,N);
    	//cout<<"hello";
    	//cin.get();
    	int capablesum=0;
    	for(i=N;i>=0;i--)
    	{
    		if(tr[nooftracks][i]==true)
    		{
    			capablesum=i;
    			break;
    		}
    	}
    	int arrtemp[20];
    	int count=0;
    	int tempS=capablesum;
    	int tempT=nooftracks;
    	//cout<<"sum:"<<capablesum<<endl;
    	//cin.get();
    	while(tempS>0)
    	{
    		
    		if((tempS-arr[tempT-1])>=0&&tr[tempT-1][tempS-arr[tempT-1]]==true)
    		{
    			arrtemp[count]=arr[tempT-1];
    			count++;
    			tempS=tempS-arr[tempT-1];
    		}
    		//cout<<tempS<<arr[tempT-1];
    		//cin.get();
    		tempT--;
    	}
    	//cout<<"hello";
    	//cin.get();
    	for(i=count-1;i>=0;i--)
    	{
    		cout<<arrtemp[i]<<" ";
    	}
    	cout<<"sum:"<<capablesum<<endl;
	}
}
