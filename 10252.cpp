using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
//#include<stdlib>
long long mat[2][26];

 int main()
 	   {
	   	   //freopen("test.txt", "r", stdin);
 		  //freopen("testO.txt", "w", stdout);
	   	   
	   	   while(1)
	   	   {
		   int k;
	   	   int flag=0;
	   	   long long i=0,j=0;
	   	   char ch;
	   	   for(i=0;i<2;i++)
	   	   for(j=0;j<26;j++)
	   	   mat[i][j]=0;
	   	   i=0;j=0;
	   	   while(1)
	   	   {
		   		   
		   		   ch=getchar();
		   		   if(ch == EOF)
		   		   {
				   				flag=-50;
				   				break;
					}
		   		   
		   		  
		   		   if(ch>=97&&ch<=122)
		   		   {
				   					 mat[i][ch-97]++;
				   }
				   if (isspace(ch)!=0)
				   i++;
				   if(i==2)
				   break;
		   }
		   if(flag==-50)
		   break;
			for(i=0;i<26;i++)
			{
			 				 if(min(mat[0][i],mat[1][i])!=0)
			 				 {
							  								long long n=min(mat[0][i],mat[1][i]);
							  								for(j=0;j<n;j++)
							  								cout<<(char)(97+i);
			                 }
		    }
		    cout<<"\n";
			}
			return 0;
			}	   
