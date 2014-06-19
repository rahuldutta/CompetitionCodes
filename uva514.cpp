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

int ip[1000];
int main()
{
    string line;
    int count=0;
    int N;
    int c=0;
	while(1)
    {
	 		scanf("%d",&N);
	 		if(N==0)
	 		{
			 		return 0;
	 		}
	 		/*if(c!=0)
	 		 cout<<"\n";
	 		 else
	 		 c=1;*/
	 		while(1)
	 		{
			 		//cout<<"hello";
			 		scanf("%d",&ip[0]);
			 		if(ip[0]==0)
			 		{
		 			     cout<<"\n";
					 	 break;
 		   			}
 		   			int i;
 		   			int counter=1;
             		stack<int> mystack;
             		for(i=1;i<N;i++)scanf("%d",&ip[i]);
					for(i=0;i<N;i++)
 		   			{
				 				
					 				while(counter<ip[i])
				                     {
				                                          mystack.push(counter++);
				                                                               
				                     }
				                     if(counter==ip[i])
				                     {
									  				   counter++;
				                      				   continue;
				                     }
				                     else if(counter>ip[i])
				                     {
									  	  if(ip[i]!=mystack.top())
									  	  {
										   						  break;
				  						  }
				  						  else
				  						  {
										   	  mystack.pop();
										   	  continue;
										  }
					  				 }
	 				}
	 				

		             if(i==N)
		             {
					  				 cout<<"Yes\n";
				 	 }
				 	 else
				 	 {
					  	 cout<<"No\n";
					 }
	 		}
	}
	 return 0;
}
