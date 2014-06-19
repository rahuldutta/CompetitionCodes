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

int ADJ[8][8];
int Color[8];

int partition(vector<int>& arr, vector<int>& arr1,int left, int right)

{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {

            while (arr[i]<pivot)     i++;
            while (arr[j]<pivot)                  j--;
            if (i <= j) {
            //if(arr[i].compare(arr[j])!=0||(arr[i].compare(arr[j])==0&&arr1[i]>=arr1[j]))
            {
            	  	tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			int tmp1=arr1[i];
			arr1[i]=arr1[j];
			arr1[j]=tmp1;
		}  
		i++;
		j--;
		  
            }
      }

     

      return i;

}

 

void quickSort(vector<int>& arr, vector<int>& arr1, int left, int right) {

      int index = partition(arr, arr1,left, right);
      if (left < index - 1)
            quickSort(arr, arr1, left, index - 1);
      if (index < right)
            quickSort(arr, arr1, index, right);

}





int degree(int i, int N)
{
	int sum=0;
	for(int j=0;j<N;j++)
		if(ADJ[i][j]==1)
			sum++;
	return sum;
}

int main()
{
	int N;
	string s;
	while(true)
	{
		/*//getline(cin,s);
		if(s.compare("#"))	
		//break;
		istringstream iss(s);
		char ch;
		while(iss>>ch)
		{
			if(ch>='A'&&ch<='Z')
			{
				
			}
		}*/
		cin>>N;
		for(int x=0;x<N;x++)
		for(int y=0;y<N;y++)
		cin>>ADJ[x][y];
		
		
		queue<int> myqueue;
		vector<int> R;
		vector<int> R1;
		R1.assign(8,0);
		while(true)
		{
			int pos=0, min=9,k;
			for(k=0;k<N;k++)
			{
				if(Color[k]>0)
				continue;
				int d=degree(k,N);
				if(d<min)
				{
					min=d;
					pos=k;
				}
			}
			R.push_back(pos);
			R1[pos]=R.size()-1;
			Color[pos]=1;
			vector<int> deg;
			vector<int> nbr;
			for(k=0;k<N;k++)
			{
			
				if(ADJ[pos][k]==1)
				{
					nbr.push_back(k);
					deg.push_back(degree(k,N));
				}
			}
			quickSort(deg,nbr,0,nbr.size()-1);
			int tt=0;
			while(tt<nbr.size())
			{
				myqueue.push(nbr[tt++]);
			}
			while(!myqueue.empty())
			{
				int C=myqueue.front();
				myqueue.pop();
				if(Color[C]==0)
				{
					R.push_back(C);
					R1[C]=R.size()-1;
					Color[C]=1;
					vector<int> deg;
					vector<int> nbr;
					for(k=0;k<N;k++)
					{
			
						if(ADJ[pos][k]==1)
						{
							nbr.push_back(k);
							deg.push_back(degree(k,N));
						}
					}
					quickSort(deg,nbr,0,nbr.size()-1);
					tt=0;
					while(tt<nbr.size())
					{
						myqueue.push(nbr[tt++]);
					}
				}
			
			}
			if(R.size()!=N)
			continue;
			else break;
	
		}
		int j;
		int bigmax=0;
		for(j=0;j<R.size();j++)
		{
			int node=R[j];
			int max=0;
			for(int h=0;h<N;h++)
			{
				if(ADJ[node][h]==1)
				{
					int temp=R1[h]-R1[node];
					if(temp>max)
					{
						max=temp;
					}
				}
			}
			if(max>bigmax)
			bigmax=max;
		}
		for(j=0;j<R.size();j++)
		cout<< R[j]<<" ";
		
		cout<<bigmax;
	
	}	
	return 0;
	
}
