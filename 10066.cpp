using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
//#include<stdlib>

 long long ip1[120];
	   	   long long ip2[120];

long long table[120][120];



 


 	   int main()
 	   {
	   	   long long flag=0;
	   	   //freopen("test.txt", "r", stdin);
		   //freopen("testO.txt", "w", stdout);
	   	   long long N1,N2;
	   	   while(cin>>N1>>N2)
	   	   {
		   		
	   	  
	   	   long long i=0,j=0;
	   	  if(N1==0&&N2==0)
	   	  {
	   	  break;
		  }
	   	   
	   	   for(i=0;i<N1;i++)
	   	   {
		   		   cin>>ip1[i];
	       }
				   
	   	   for(i=0;i<N2;i++)
	   	   {
		   		   cin>>ip2[i];
				   }
    for (i=0;i<(N1+1);i++)
	{    
        for(j=0; j<(N2+1);j++)
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
	   
	   	   cout<<"Twin Towers #"<<(flag+1)<<"\n";
	   
	   cout<<"Number of Tiles : "<<table[N1][N2]<<"\n\n";
	   flag++;
	   }
	   return 0;
	   }
