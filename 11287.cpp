using namespace std;
#include<iostream>
#include<stdio.h>
#include<math.h>
int main()
{
 	long long a,p;
 while(	cin>>p>>a)
 {
  		if(p==0&&a==0)
  		break;
     long long c = 1;
     long long mod=p;
     long long i=1,k=1;
        long long atemp=a;
        int flag=0;
        if(p%2==0&&p!=2)
        flag=-1;
        else if(p%3==0&&p!=3)
        flag=-1;
        else
        {
		 	for(i=1;(6*i+1)<sqrt(p);i++)
		 	if(p%(6*i+1)==0||p%(6*i-1)==0)
		 	{
			 		  flag=-1;
			 break;
			 }
			 }
    while( p > 0)
    {
        if ((p & 1)==1)
        {
           c = ((c *a))% mod;
         //  cout<<"mmm"<<c<<" "<<p<<"kkk";
           //getchar();
		   }
        p= p>>1;
        a= (a*a) % mod;
		}
 if(c==atemp&&flag==-1)
 cout<<"yes\n";
 else
 cout<<"no\n";
}
return 0;
}
