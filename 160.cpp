using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>

long long count1=0;
long long arr[21]={11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
long long power( long long n, long long p )
  {
   if (n == 1) return 1;
   long long k=n;
   while(k%p==0)
   {
   			 count1++;
      k=k/p;
}
	  return k*power(n-1,p);
}


int main()
{
 	 //freopen("test.txt", "r", stdin);
 	//	  freopen("testO.txt", "w", stdout);
 	long long N;
 	while(cin>>N)
 	{
	 			 if(N==0)
	 			 break;
	 			 printf("%3d! =",N);
	 			 long long i,j,k,flag;
	 			 if(2<=N)
	 			 {
				  				count1=0;
				  				long long t= power(N,2);
	 			 				printf("%3d",count1);
				 }
	 			  if(3<=N)
	 			  {
				   				   count1=0;
				  				long long t= power(N,3);
	 			 				printf("%3d",count1);
								  				  }
				  if(5<=N)
	 			  {
				   				   count1=0;
				  				long long t= power(N,5);
	 			 				printf("%3d",count1);
				  }
				  if(7<=N)
	 			  {
				   				   count1=0;
				  				long long t= power(N,7);
	 			 				printf("%3d",count1);
				  }
				  flag=4;
				  for(i=0;arr[i]<=N&&i<21;i++)
				  {
				  if(flag==15)
						   printf("\n      ");	
				   		printf("%3d",(N/arr[i]));
						   flag++;
						   			                
 					}	 
 					cout<<"\n";
    }
    return 0;
}
