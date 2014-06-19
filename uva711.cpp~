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

bool arr[60002][7]={{false}};
int arr1[60001][7];

bool calcTrue1(int arra[], int Sum, int index)
{
	if(Sum<0)
	return false;
	if(Sum==0)
	return true;
	if(index==6)
	return false;
	
	if(arr1[Sum][index]!=-1) return arr1[Sum][index];
	
	int ret=0;
	for(int i=0;i<=arra[index];i++)
	{
		ret=ret|calcTrue1(arra,Sum-(i)*(index+1),index+1);
	}
	arr1[Sum][index]=ret;
	return arr1[Sum][index];
}

bool calcTrue(int arra[], int Sum)
{
//cout<<"hello";
	
	//cout<<Sum<<endl;
	//cin.get();
	for(int s=0;s<=Sum;s++)
	{
		for(int pos=0;pos<=6;pos++)
		{
			if(pos == 0 && s !=0)
				arr[s][pos]=false;
			else if(s == 0)
				arr[s][pos]=true;
			else
			{
				bool result=arr[s][pos-1];
				int stemp=s;
				for(int i=0;i<arra[pos-1]&&result!=true;i++)
				{
					
					if(stemp-pos>=0)
					{
						result=result | arr[stemp-pos][pos-1];
						
					}
					stemp=stemp-pos;
				}
				arr[s][pos]=result;
			}
		}
	}
	
	/*for(int i=0;i<=Sum;i++)
	{
		for(int j=0;j<=6;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return arr[Sum][6];
	//return true;
}

int main()
{
	int coll_no=1;
	while(1)
	{
		memset(arr1,-1,sizeof(arr1));
		int F[6];
		int Sum=0;
		int zerocnt=0;
		for(int i=1;i<=6;i++)
		{
			int count;
			cin>>count;
			if(count==0)
				zerocnt++;
			if (count>6) 
			count = 6 + ((count -6)%2); 
			F[i-1]=count;
			Sum=Sum+count*i;
		}
		
		//cout<<Sum<<" "<<zerocnt<<endl;
		//cin.get();
		if(zerocnt==6)
			return 0;
		if(Sum%2!=0)
		{
			cout<<"Collection #"<<coll_no<<":\n";
			cout<<"Can't be divided.\n";			
		}
		else if(calcTrue(F,Sum/2))
		{
			cout<<"Collection #"<<coll_no<<":\n";
			cout<<"Can be divided.\n";
		}
		else
		{
			cout<<"Collection #"<<coll_no<<":\n";
			cout<<"Can't be divided.\n";
		}
		cout<<endl;
		coll_no++;
	}
	return 0;
}
