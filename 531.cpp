using namespace std;
#include <iostream>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
//#include<stdlib>

 char ip1[120][100];
	   	   char ip2[120][100];

long long table[120][120];
char str[120][100];
long long pos=0;

 
 int calc(long long i,long long j)
  {
        if (i == 0 || j == 0)
            {
			 return 0; 	 
			 }
        else if (strcmp(ip1[i-1],ip2[j-1])==0)
        {
            strcpy(str[pos],ip1[i-1]);
            pos++;
			 calc(i-1, j-1) ;
			 }
        else if (table[i-1][j] > table[i][j-1])
        {
            calc(i-1, j);
			}
        else
        {
            calc(i, j-1);
			}   
}         


 	   int main()
 	   {
	   	  // freopen("test.txt", "r", stdin);
 		   //freopen("testO.txt", "w", stdout);
	   	   
	   	   while(1)
	   	   {
		   		   int k;
	   	   int flag=0;
	   	   long long l1=0;
	   	   long long l2=0;
	   	  pos=0;
	   	   long long i=0,j=0;
	   	   char ch;
	   	   
	   	   while(1)
	   	   {
		   		   
		   		   ch=getchar();
		   		   if(ch == EOF)
		   		   {
				   				flag=-50;
				   				break;
					}
		   		   if(ch=='#')
		   		   break;
		   		  // cout<<"\n"<<ch<<" "<<(int)ch<<" "<<i<<" "<<j;
		   		  
		   		   if(ch>=97&&ch<=122)
		   		   {
				   					 ip1[i][j]=ch;
				   					 j++;
				 }
				 else if (isspace(ch)!=0&&j!=0)//((ch==' '&&j!=0)||(ch=='\n'&&j!=0))
				 {
				  	  ip1[i][j]='\0';
				  	  i++;
				  	  j=0;
				  }
				  else continue;
		   		   }
		   		   if(flag==-50)
		   		   break;
		   		 //  ip1[i][j]=NULL;
		   		   l1=i;
		   		   //cout<<l1;
		   		   i=0;
		   		   j=0;
		   		     while(1)
	   	   {
		   		   ch=getchar();
		   		   if(ch=='#')
		   		   break;
		   		   if(ch>=97&&ch<=122)
		   		   {
				   					 ip2[i][j++]=ch;
				   					 }
				   					 else if (isspace(ch)!=0&&j!=0)//((ch==' '&&j!=0)||(ch=='\n'&&j!=0))
				   					 {
									  	  ip2[i][j]='\0';
									  	  i++;
									  	  j=0;
									  }
									  	  else continue;
		   		   }
		   		   //ip2[i][j]=NULL;
		   		  l2=i;
		   		  
		   		 // cout<<l2;
		   		 // getchar();
    for (i=0;i<(l1+1);i++)
	{    
        for(j=0; j<(l2+1);j++)
		{
		 		    if (i == 0 ||j == 0)
                table[i][j] = 0;
            else if (strcmp(ip1[i-1],ip2[j-1])==0)
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
	  
	  k=calc(l1,l2);
	   for(i=pos-1;i>=0;i--)
	   {
	   if(i>0)
	   {
	   cout<<str[i]<<" ";
	   }
	   else
	   {
	   	 cout<<str[i]<<"\n";  
	   }
	   }
	   
	   }
	   return 0;
	   }
