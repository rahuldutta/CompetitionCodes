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

void permutate(int arr[],int i, int N, int K, vector<int> result)
{
 	 
 	 result.push_back(arr[i]);
 	 K--;
	 if(K==0)
 	 {
	  for(int k=0;k<result.size()-1;k++)
	  cout<<result[k]<<" ";
	  cout<<result[result.size()-1];
 	  cout<<"\n";
	 }
 	 else{
		 	  
		 for(int j=i+1;j<N;j++)
	 	 {
		  		 if((N-j)<K)
		  		 break;
		  		 permutate(arr,j,N,K,result);
		 }
	 }
}

int main()
{
 	int * arr;
 	int N;
 	int c=0;
 	while(cin>>N)
 	{
	 			 if(N==0)
	 			 return 0;
	 			 if(c==0)
	 			 c=1;
	 			 else
	 			 cout<<"\n";
	 			 arr=new int[N];
	 			 for(int i=0;i<N;i++)
	 			 cin>>arr[i];
	 			 vector<int> cont;
	 			 for(int i=0;i<=(N-6);i++)
	 			 permutate(arr,i,N,6,cont);
	 }
	 return 0;
}
