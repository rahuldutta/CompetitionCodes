using namespace std;
#include<iostream>
#include<stdio.h>
#include<math.h>
int main()
{
 	long long cas;
 	cin>>cas;
 	long long k=1;
 while(	k<=cas)
 	{
	 	long long u,l,i,j,max=1,s,p,flag,lo,primch=0;
	 	cin>>l>>u;
	 j=l;
	 lo=j;
 	
	 while(j<=u)
	 {
	  			primch=0;
	  			s=1;
	  			p=j;
	  			if(p%2==0)//||p%(6*i-1)==0)
		 	{
			 	primch=-1;
			 		  flag=0;
			 		  while(p%2==0)
			 		  {
					   					 flag=flag+1;
					   					 p=p/2;
										 }
			 s=s*(flag+1);
			 }
			 if(p%3==0)//||p%(6*i-1)==0)
		 	{
			 							primch=-1;
			 		  flag=0;
			 		  while(p%3==0)
			 		  {
					   					 flag=flag+1;
					   					 p=p/3;
										 }
			 s=s*(flag+1);
			 }
 	for(i=1;(6*i+1)<sqrt(j)&&p>1;i++)
 	{
	 							
		 	if(p%(6*i+1)==0)
		 	{
			 								 primch=-1;
			 		  flag=0;
			 		  while(p%(6*i+1)==0)
			 		  {
					   					 flag=flag+1;
					   					 p=p/(6*i+1);
										 }
			 s=s*(flag+1);
			 }
			 if(p%(6*i-1)==0)//||p%(6*i-1)==0)
		 	{
			 								  primch=-1;
			 		  flag=0;
			 		  while(p%(6*i-1)==0)
			 		  {
					   					 flag=flag+1;
					   					 p=p/(6*i-1);
					  }
			 s=s*(flag+1);
			 }
	 }
	 if(primch==0&&j!=1)
	 s=2;
	 if(s>max)
	 {
	  		  max=s;
	  		  lo=j;
			  }
			  j++;
}
if(k<cas)
printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,u,lo,max);			

k++; 
}
 	return 0;
}
