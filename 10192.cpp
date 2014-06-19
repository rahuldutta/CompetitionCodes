using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
//#include<stdlib>

 char ip1[120];
	   	   char ip2[120];

long long table[120][120];


     


 	   int main()
 	   {
	   	   //freopen("test.txt", "r", stdin);
 		  //freopen("testO.txt", "w", stdout);
	   	   long long serial=0;
	   	     int flag=0;
	   	   while(1)
	   	   {
		   		  
	   	 
	   	   long long l1=0;
	   	   long long l2=0;
	   	 
	   	   long long i=0,j=0;
	   	   char ch;
	   	   
	   	   while(1)
	   	   {
		   		   
		   		   ch=getchar();
		   		   if(ch == '#')
		   		   {
				   				flag=-50;
				   				break;
                   }
		   		   if(ch=='\n')
		   		   break;
		   		   // cout<<"\n"<<ch<<" "<<(int)ch<<" "<<i<<" "<<j;
		   		  
		   		  if((ch>=97&&ch<=122)||(ch>=65&&ch<=90)||(ch>=48&&ch<=57)||ch==32)
		   		   {
				   					 ip1[i]=ch;
				   					 i++;
				   }
				 
		   }
		   l1=i;
		  // cout<<l1;
		   if(flag==-50)
		    break;
		    
		   	i=0;
		   		  
		  while(1)
	   	   {
		   		   
		   		   ch=getchar();
		   		  
		   		   if(ch=='\n')
		   		   break;
		   		  
		   		   if((ch>=97&&ch<=122)||(ch>=65&&ch<=90)||(ch>=48&&ch<=57)||ch==32)
		   		   {
				   					 ip2[i]=ch;
				   					 i++;
		           }
				 
		   }
		   l2=i;
		   		  
		   		  //cout<<l2;
		   		 // getchar();
    for (i=0;i<(l1+1);i++)
	{    
        for(j=0; j<(l2+1);j++)
		{
		 		    if (i == 0 ||j == 0)
                table[i][j] = 0;
            else if (ip1[i-1]==ip2[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
		    }
            else
            { 
                table[i][j] = max(table[i-1][j], table[i][j-1]);
		    }
		  //  cout<<table[i][j]<<"  ";
	   }
	   //cout<<"\n";
	   }
	  
cout<<"Case #"<<(serial+1)<<": you can visit at most "<<table[l1][l2]<<" cities.\n";
	   serial++;
	   }
	   return 0;
	   }
