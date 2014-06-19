using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
//#include<stdlib>
long long arr[1000001];
long long gc=0;
void gcd(long long a,long long b)
{
if(b==0)
 {
 gc=a;
 return;
}
gcd(b,a%b);
}


 int main()
 	   {
	   	 //freopen("test.txt", "r", stdin);
 		 //freopen("testO.txt", "w", stdout);

long long N;
while(cin>>N)
{
 			 
long long p=(long long)(sqrt(N)); 
long long r,s,i;
long long count=0;
long long flag1=0;
for(i=0;i<=N;i++)
{
arr[i]=0;
}
for(r=1;r<=p;r++)
{
 				 for(s=r+1;s<=p;s++)
 				 {
				  					  gc=0;
				  					 gcd(r+s,s-r);
								   						   
															  if(gc==1)
															  {
				  				  double sum=pow((pow(r,2)-pow(s,2)),2)+pow((2*r*s),2);
				  				  double sum1=((pow(r,2)+pow(s,2)),2);
				  				  long long t=r*r+s*s;
				  				  	if(t>N)
				  				  continue;
								  if((sum-sum1)<=0.0000001||(sum-sum1)>=-0.0000001)
								  {
								   						   int n1=s*s-r*r;
								   						   int n2=2*r*s;
								   						   int n3=s*s+r*r;
								   						  // cout<<n1<<" "<<n2<<" "<<n3<<"\n";
								   						   //getchar();
															  arr[n1]=1;
								   						   arr[n2]=1;
								   						   arr[n3]=1;
								   						  // cout<<r<<s<<"\n";
								   						 
								   						 
								   						  
								   						   
															  count++;
															  
															  for(i=2;i<=(N/n3);i++)
															  {arr[n1*i]=1;
															  arr[n2*i]=1;
															  arr[n3*i]=1;
															  }
															  }
 						          }
				  }
}
long long flag=0;
for(i=1;i<=N;i++)
{
 				if(arr[i]==0)
 				flag++;
 				}
cout<<count<<" "<<flag<<"\n";
//system("pause");
}
return 0;
}
