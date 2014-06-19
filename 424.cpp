using namespace std;
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>

 int main()
 	   {
	   	   long long time=0;
	 //freopen("test.txt", "r", stdin);
 	 //freopen("testO.txt", "w", stdout);
	   	  string N[200];
	   	  long long i=0,pos=0,j=0,carry=0,max=0;
	   	  long long arr[200]={0};
	   	  while(1)
	   	  {
		   		  cin>>N[pos];
		   		  if(N[pos]=="0")
		   		  {
				   			break;
				   			}
				   			for(i=0;i<N[pos].length();i++)
				   			{
							 						   long long sum=arr[i]+N[pos][N[pos].length()-1-i]-48+carry;
							 						   arr[i]=sum%10;
							 						   carry=sum/10;
 						   }
							 						   if(carry!=0)
							 						   {
							 						   arr[i]+=carry;
							 						   i++;
													   }
							 						   carry=0;
							 						   
							 				if(i>max)
											 max=i-1;		   
		   		  pos++;
		 }
		  for(i=max;i>=0;i--)
		  cout<<arr[i];
		  cout<<"\n";
		  //cin>>j;
		  //getchar();
		  return 0;
		  }
		   					
 		  
