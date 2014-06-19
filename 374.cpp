using namespace std;
#include<iostream>
#include<stdio.h>
#include<math.h>
long long power( long long n , long long p ,long long M )
  {
   if (p == 0) return 1;
   if (p == 1) return n;
   
   if(p%2!=0)
	  
	 return (((n%M) * (power( (n%M * n%M)%M, (p-1) / 2 ,M))%M)%M);
   else
      return power( (n%M * n%M)%M, p / 2,M );
}

int main()
{
 	long long B,P,M;
 	while(cin>>B>>P>>M)
 	{
	 				   cout<<power(B,P,M)<<"\n";
    }
    return 0;
}
