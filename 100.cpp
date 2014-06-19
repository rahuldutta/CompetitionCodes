using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//#include<stdlib>
long long s=0;
long long arr[1000000]={0};
long long recurv(long long n)
{
 	 s++;
 	 
 	 if(n==1)
 	 return 0;
 	 if(n%2==0)
 	 {
	  		  
	  		   recurv(n/2);
	  		   }
	  		   else
	  		   {
			   	 
			   	   recurv(3*n+1);
			   	   }
			   	   
 }
 
 int main()
 	   {
	   	 //freopen("test.txt", "r", stdin);
 		 //freopen("testO.txt", "w", stdout);


long long i,j,k,ind,max=0;
for(i=1;i<1000000;i++)
{
 					  s=0;
 					  long long temp=recurv(i);
 					  arr[i]=s;
 					  }
while(cin>>i>>j)
{
 				
 				max=0;
 				if(j>=i)
 				ind=1;
 				else
 				ind=-1;
 				for(k=i;k!=(j+ind);k+=ind)
 				{
				 	
				 	if(arr[k]>=max)
				 	max=arr[k];
					 			 
				 				 }
 			 
 			 
 			 cout<<i<<" "<<j<<" "<<max<<"\n";
}
			 return 0;
			 }
