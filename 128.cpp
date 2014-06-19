using namespace std;
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
 	long long sum=0,i=0;
 	
 	 char str[2000];
 	 while(cin.getline(str,2000))
 	 {
	  							 if(strcmp(str,"#")==0)
	  							 break;
	  							 sum=0;
	  	for(i=0;i<strlen(str);i++)
		  {
		   						  sum=sum<<8;//sum=sum*2^8
		   						  sum=sum%34943;
									 sum=sum+str[i];
		   						  sum=sum%34943;
		   						  
		  }

		  
		 
		   sum <<= 16;
        sum =sum% 34943;
      sum = (34943 - sum)%34943 ;
 int c=sum%16+((sum/16)%16)*16;
		  int c1=sum/256;
	

							printf("%02X %02X\n",c1,c);
     }		 						 
     return 0;
}
