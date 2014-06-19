using namespace std;
#include <iostream>
#include <stdio.h>
#include<string>
#include<ctype.h>
#include<math.h>

//#include<stdlib>

long long arr[100][2];
char chr[500][500];
int main()
{
 	//freopen("test.txt", "r", stdin);
 	//freopen("testO.txt", "w", stdout);

 	long long i,j,N,k,m,flag,pos=0,r1,r2,c1,c2,mr,mc,min,dis,pos1;
 	string ch;
 	char ch1='A';
 	for(i=0;i<500;i++)
	for(j=0;j<500;j++)
	chr[i][j]='Z';
 	while(1)
 	{
	 		//scanf("%c",&ch);
	 		cin>>ch;
	 		if(ch=="#")
	 		break;
	 		if(ch=="I")
	 		{
			 		   cin>>arr[pos][0];
			 		   cin>>arr[pos][1];
			 		   pos++;
	        }
	        else if(ch=="R")
	        {
			 	 cin>>r1>>c1>>r2>>c2;
			 	 for(i=r1;i<=(r2);i++)
			 	 for(j=c1;j<=(c2);j++)
			 	 chr[i][j]=ch1;
			 	 ch1++;
			 }
			 else if(ch=="M")
			 {
			  	  cin>>mr>>mc;
			  	  if(chr[mr][mc]!='Z')
			  	  cout<<chr[mr][mc]<<"\n";
			  	  else
			  	  {
				   	  
				   	  min=750000;
				   	  for(i=0;i<pos;i++)
				   	  {
					   		dis=(long long)(pow((arr[i][0]-mr),2)+pow((arr[i][1]-mc),2));	
							   	if(dis<min)
							   	{
								 		   min=dis;
								 		   pos1=i;
					 		    }
				      }
							printf("%3d",(pos1+1));
								for(i=pos1+1;i<pos;i++)
				   	  {
					   		dis=(long long)(pow((arr[i][0]-mr),2)+pow((arr[i][1]-mc),2));	
							   	if(dis==min)
							   	{
								 		printf("%3d",(i+1));
					 		    }
								}
								cout<<"\n";
								}
								   	
			    	  }
			    	  continue;
				  }
			  return 0;
			  }
		
	 		
