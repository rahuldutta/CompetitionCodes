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
const int maxn = 301;
long long f1[maxn][maxn][maxn];
//long long f2[maxn][]maxn

//taken help

void sumCheck()
{
	//cout<<sum<<endl;
	//cin.get();

	int i,j,k;
	for(i=0;i<301;i++)
	{
		for(k=0;k<301;k++)
		{
			if(i!=0)
			{
				f1[i][0][k]=0;
				f1[i][k][0]=0;
			}
			f1[0][i][k]=1;
		}
	}
	
	for(i=0;i<301;i++)
	{
		for(j=1;j<301;j++)
		{
			for(k=1;k<301;k++)
			{
				if((i-j)>=0)
				{
					f1[i][j][k]=f1[i][j-1][k]+f1[i-j][j][k-1];
				}
				else
				{
					f1[i][j][k]=f1[i][j-1][k];
				}
			}
		}
	}
	

}

int main()
{
	int i,j,a[3];
	sumCheck();
	//cout<<f1[248][248][248]<<endl;
	//cout<<(f1[248][248][178]-f1[248][248][73])<<endl;
	//cout<<f1[248][248][93]<<endl;
	
	string line;
	while(getline(cin,line))
	{
		stringstream ss;
		ss.clear();
    	ss.str("");
    	ss<<line;
    	int index=0;
    	
    	 while(!ss.eof())
		 {
			if(isspace(ss.peek()))
			  ss >> ws;
			else
			{
			  ss>>a[index];
			  index++;
			}
		 }
		 if(index==3)
		 {
		 	
		 	if(a[2]==0&&a[1]==0&&a[0]==0)
		 	cout<<1<<endl;
		 	else if(a[2]==0&&a[1]==0)
		 	cout<<0<<endl;
		 	else
		 	{
		 	if(a[2]>300)
		 	a[2]=300;
		 	if(a[1]==0)
		 	a[1]=1;
		 	if(a[1]>300)
		 	cout<<0<<endl;
		 	else
		 	cout<<(f1[a[0]][a[2]][300]-f1[a[0]][a[1]-1][300])<<endl;
		 	//cout<<(f1[a[0]][a[0]][a[2]]-f1[a[0]][a[0]][a[1]-1])<<endl;
		 	}
		 }
		 else if(index==2)
		 {
		 	if(a[1]>300)
		 	a[1]=300;
		 	cout<<f1[a[0]][a[0]][a[1]]<<endl;
		 }
		 else
		 {
		 	cout<<f1[a[0]][a[0]][300]<<endl;
		 }
	}
	
	//cout<<t[300][6]<<" "<<t[3][6]<<" "<<t[2][6]<<" "<<t[5][6]<<endl;

}
