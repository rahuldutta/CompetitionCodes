using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define const 2000000000
//#include<stdlib>
long long s=0;
long long arr[20];

int main()
{
 	freopen("test.txt", "r", stdin);
 	freopen("testO.txt", "w", stdout);

 	long long i,j,N,k,m,flag,start,end,temp;
 	while(cin>>N>>k>>m)
 	{
	 				   if(N==0&&m==0&&k==0)
	 				   break;
	 for(i=0;i<20;i++)
 	arr[i]=i+1;
 	flag=0;
 	start=0;
 	end=N-1;
 	while(flag!=N)
 	{
	 			  i=0;j=0;
	 			  while(i!=k)
	 			  {
				   			 temp=(start+N*const+j)%N;
	 			  if(arr[temp]!=0)
	 			  i++;
	 			  j++;
				  }
				   start=(start+N*const+j-1)%N;
	 			   i=0;j=0;
	 			   while(i!=m)
	 			  {
				   			  temp=(end+N*const-j)%N;
	 			  if(arr[temp]!=0)
	 			  i++;
	 			  j++;
				  }
				 
				  end=(end+N*const-j+1)%N;
				  //cout<<start<<" "<<end<<" "<<i<<"\n";
				  //getchar();
	 			  if(start!=end)
	 			  {
				   				printf("%3lld%3lld",arr[start],arr[end]);
				   				arr[start]=0;
				   				arr[end]=0;
				   				flag+=2;
				   				if(flag!=N)
				   				cout<<",";
				   				else
				   				cout<<"\n";
				   				}
				   				else
				   				{
								 	printf("%3lld",arr[start]);
								 	arr[start]=0;
								 	flag+=1;
								 	if(flag!=N)
				   				cout<<",";
				   				else
				   				cout<<"\n";
								}
				   				start=(start+N*const+1)%N;
				   				end=(end+N*const-1)%N;
	 			  }
}
return 0;
}
